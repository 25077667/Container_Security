#include <string.h>
int main()
{
    char arr[8];
    char *str = "OVERFLOWAAAAAAAAAAAAAAAAaAA";
    strcpy(arr, str);
    return 0;
}