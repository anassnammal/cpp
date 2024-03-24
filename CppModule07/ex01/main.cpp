#include <iostream>
#include "iter.hpp"
#include "print.hpp"

int main(void)
{
    // Test case 1: Array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    int intArrayLength = sizeof(intArray) / sizeof(int);
    std::cout << "Test case 1: Array of integers\n";
    iter<int, int, void(*)(int const &)>(intArray, intArrayLength, printValue<int>);
    std::cout << "\n";

    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    int charArrayLength = sizeof(charArray) / sizeof(char);
    std::cout << "Test case 2: Array of characters\n";
    iter<char, int, void(*)(char const &)>(charArray, charArrayLength, printValue<char>);
    std::cout << "\n";

    std::string stringArray[] = {"1337", "future", "is", "loading"};
    int stringArrayLength = sizeof(stringArray) / sizeof(std::string);
    std::cout << "Test case 3: Array of strings\n";
    iter<std::string, int, void(*)(std::string const &)>(stringArray, stringArrayLength, printValue<std::string>);
    std::cout << "\n";

    return 0;
}