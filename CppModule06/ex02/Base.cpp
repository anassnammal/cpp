#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void)
{

}

Base    *Base::generate(void)
{
    switch ((rand() % 3))
    {
    case 0:
        return (new A());
    case 1:
        return (new B());
    case 2:
        return (new C());
    }
    return (nullptr);
}

void Base::identify(Base* p)  
{
    if (dynamic_cast<A*>(p))
        std::cout << "the type of the instance is : class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "the type of the instance is : class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "the type of the instance is : class C" << std::endl;
}

void Base::identify(Base &p)
{
    try
    {
        A a = dynamic_cast<A&>(p);
        std::cout << "the type of the instance is : class A" << std::endl;
    }
    catch(const std::bad_cast& e)
    {
        try
        {
            B b = dynamic_cast<B&>(p);
            std::cout << "the type of the instance is : class B" << std::endl;
        }
        catch(const std::bad_cast& e)
        {
            try
            {
                C c = dynamic_cast<C&>(p);
                std::cout << "the type of the instance is : class C" << std::endl;
            }
            catch(const std::bad_cast& e)
            {
                std::cout << "the type of the instance is : undefined" << std::endl;
            }
        }
    }
}


