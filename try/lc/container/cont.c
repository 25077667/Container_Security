#define _GNU_SOURCE
#include "cont.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#define STK_SIZE 327680

static long c_pid;
static char *c_stkptr;

static int run(void *argv)
{
    char **arg = *(char ***)argv;
    return execvp(arg[0], arg);
}

static inline pid_t loader(char *argv[])
{
    return clone(run, c_stkptr, CLONE_NEWPID | SIGCHLD, &argv);
}

int cont_start(char *argv[], int do_wait)
{
    c_stkptr = (char *) malloc(STK_SIZE);
    c_pid = (long) loader(argv);
    printf("Start container: %s with id: %d\n", argv[0], c_pid);
    // FIXME: attach child
    if (do_wait)
        waitpid(c_pid, NULL, 0);
}

int cont_stop()
{
    kill(c_pid, SIGTERM);
    free(c_stkptr);
}