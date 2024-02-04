#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    Animal  const *meta = new Animal();
    Animal  const *j = new Dog();
    Animal  const *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    return 0;
}

