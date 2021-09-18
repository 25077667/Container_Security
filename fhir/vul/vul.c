#include <stdio.h>
#include <unistd.h>

char buf[100] = {0};

int main()
{
    scanf("%s", buf);
    return execve(buf, 0, 0);
}
