#include <iostream>
class Object
{
    int *arr;

public:
    Object()
    {
        arr = new int[5];
    }
    ~Object()
    {
        std::cerr << "Freed" << std::endl;
        delete[] arr;
    }
};