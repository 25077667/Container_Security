#include <exception>
#include <iostream>
auto get_ptr()
{
    auto ptr = new int[100];
    throw std::runtime_error("Oh! unexpected runtime error.");
    return ptr;
}

int main()
{
    try
    {
        auto ptr = get_ptr();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}