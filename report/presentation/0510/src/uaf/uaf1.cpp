#include <functional>
#include <iostream>
#include <string>

auto bad()
{
    std::string loc_str("loc_str");
    return std::ref(loc_str);
}

int main()
{
    auto no = bad();
    std::cout << no.get() << std::endl;
}