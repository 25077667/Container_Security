#include <stdio.h>
#include <stdlib.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MOUNT_POINT "/mnt/foo"
#define MOUNT_TARGET "/dev/sda2"
#define SECRET_PATH "/home/scc/secret"

#define TRY_THROW(op, is_fail)       \
    do {                             \
        typeof(is_fail) _err = (op); \
        if (_err == (is_fail)) {     \
            perror(#op);             \
            exit(_err);              \
        }                            \
    } while (0)

char buf[100];

int main()
{
    TRY_THROW(mkdir(MOUNT_POINT, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH), -1);
    TRY_THROW(mount(MOUNT_TARGET, MOUNT_POINT, "ext4", MS_SYNCHRONOUS, ""), -1);

    FILE *secret_file;
    TRY_THROW((secret_file = fopen(MOUNT_POINT SECRET_PATH, "r")), NULL);

    char *ret;
    TRY_THROW(((ret = fgets(buf, sizeof(buf), secret_file)) && puts(buf)),
              (ret != buf));
    fclose(secret_file);

    return 0;
}
