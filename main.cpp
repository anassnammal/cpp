#include <iostream>
#include <iomanip>
#include <string>

int main(void)
{
    std::string ss = "01234";
    std::cout << ss.replace(9, ss.npos - 9, ".") << std::endl;
    
    return 0;
}
