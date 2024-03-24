#include <iostream>
#include "Array.hpp"

int main()
{
    Array<int> arr1;
    std::cout << "arr1 size: " << arr1.size() << std::endl; // Expected output: 1

    Array<int> arr2(5);
    std::cout << "arr2 size: " << arr2.size() << std::endl; // Expected output: 5

    Array<int> arr3(arr2);
    std::cout << "arr3 size: " << arr3.size() << std::endl; // Expected output: 5

    Array<int> arr4;
    arr4 = arr3;
    std::cout << "arr4 size: " << arr4.size() << std::endl; // Expected output: 5

    arr4[0] = 10;
    arr4[1] = 20;
    arr4[2] = 30;
    std::cout << "arr4[0]: " << arr4[0] << std::endl; // Expected output: 10
    std::cout << "arr4[1]: " << arr4[1] << std::endl; // Expected output: 20
    std::cout << "arr4[2]: " << arr4[2] << std::endl; // Expected output: 30

    try
    {
        std::cout << "arr4[5]: " << arr4[5] << std::endl; // Expected output: Array index out of bounds exception
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}