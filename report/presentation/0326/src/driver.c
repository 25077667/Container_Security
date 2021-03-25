#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cont.h"

void help(const char *name)
{
    fprintf(stderr, "Usage: \n%s [-d] Command [Args] \n", name);
    fprintf(stderr, "-d is run as daemon in background\n", name);
    exit(1);
}

int check_arg(int argc, char *argv[]) {
    return (argc < 2 || (argc == 2 && !strcmp(argv[1], "-d")));
}

int main(int argc, char *argv[])
{
    int do_wait = 1;
    if (check_arg(argc, argv))
        help(argv[0]);
    if(!strcmp(argv[1], "-d"))
        do_wait = 0;

    cont_start(argv + 1, do_wait);

    if(!do_wait)
        cont_stop();
    return 0;
}