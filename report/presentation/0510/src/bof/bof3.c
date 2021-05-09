#include <string.h>
int main()
{
    char arr[8];
    char *str = "OVERFLOWAAAAAAAAAAAAAAAAaAA";
    strncpy(arr, str, sizeof(arr));
    return 0;
}