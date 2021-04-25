#include <array>
#include <fstream>
#include <string>

std::array<int, 10> arr{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int main()
{
    for (const auto &i : arr)
        std::ofstream ofs(std::to_string(i));
    return 0;
}
