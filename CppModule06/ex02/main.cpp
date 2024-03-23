#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    Base    base;
    srand(time(NULL));
    for (size_t i = 0; i < 9; i++)
    {
        Base    *ptr = base.generate();
        base.identify(ptr);
        base.identify(*ptr);
        delete ptr;
    }
    return 0;
}

