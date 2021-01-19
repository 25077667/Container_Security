#define _GNU_SOURCE
#include "cont.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // strerror
#include <sys/mount.h>
#include <sys/wait.h>
#include <unistd.h>
#define STK_SIZE 327680

static long c_pid;
static char *c_stkptr;

static void isol()
{
    unshare(CLONE_FILES | CLONE_FS | CLONE_SYSVSEM | CLONE_NEWCGROUP);
    sethostname("container", 10);
    if (chroot("./rootfs"))
        perror("chroot error");

    printf("In container PID: %ld\n", (long) getpid());
}

static int run(void *argv)
{
    char **arg = (char **) argv;
    isol();
    chdir("/");

    int ret = execvp(arg[0], arg);
    if (ret)
        printf("%s in container\n", strerror(errno));

    return ret;
}

static inline pid_t loader(char *argv[])
{
    return clone(run, c_stkptr + STK_SIZE,
                 CLONE_NEWNS | CLONE_NEWUTS | CLONE_NEWPID | SIGCHLD, argv);
}

int cont_start(char *argv[], int do_wait)
{
    c_stkptr = (char *) malloc(STK_SIZE);
    c_pid = (long) loader(argv);
    if (c_pid)
        printf("%s on creating container\n", strerror(errno));
    printf("Start container: %s with clone id: %d\n", argv[0], c_pid);
    // FIXME: attach child
    if (do_wait)
        waitpid(c_pid, NULL, 0);
}

int cont_stop()
{
    kill(c_pid, SIGTERM);
    free(c_stkptr);
}