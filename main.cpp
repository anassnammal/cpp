#include <iostream>
#include <limits>

int main(void)
{
    int *a = new int[5];
    for (size_t i = 0; i < 5; i++)
    {
        a[i] = i;
        std::cout << a[i] << std::endl;
    }
    std::cout << a[6] << std::endl;
    
    delete[] a;
    return 0;
}
