#include <iostream>
#include <limits>

int main(void)
{
    std::cout << std::fixed;
    std::cout << "char      : " << std::numeric_limits<char>::max() << std::endl;
    std::cout << "char      : " << std::numeric_limits<char>::min() << std::endl;
    std::cout << "int       : " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "int       : " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "float     : " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "float     : " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "double    : " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "double    : " << std::numeric_limits<double>::min() << std::endl;
    return 0;
}
