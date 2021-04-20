int wrong(int *arr, size_t len, int target)
{
    int begin = 0, end = len;
    while (begin <= end)
    {
        int mid = (begin + end) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            end = mid;
        else
            begin = mid;
    }
    return -1;
}

int correct(int *arr, size_t len, int target)
{
    int begin = 0, end = len;
    while (begin <= end)
    {
        int mid = (begin >> 1) + (end >> 1);
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            end = mid;
        else
            begin = mid;
    }
    return -1;
}