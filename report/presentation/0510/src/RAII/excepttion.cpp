#include <exception>
#include "Obj.hpp"

void f()
{
    Object o;
    throw std::runtime_error("Oops!!");
    return;
}

int main()
{
    try {
        f();
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
