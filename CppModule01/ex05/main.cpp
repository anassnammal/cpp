#include "Harl.hpp"

int main(void)
{
    Harl        harl;
    std::string input;
    
    do
    {
        std::getline(std::cin, input);
        harl.complain(input);
    } while (std::cin.good());

    return (0);
}