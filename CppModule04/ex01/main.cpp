#include "Dog.hpp"
#include "Cat.hpp"

#define SIZE 10

int main(void)
{
    Animal *animals[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        if (i % 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < SIZE; i++)
        animals[i]->makeSound();
    for (int i = 0; i < SIZE; i++)
        delete animals[i];

    // deep copy test
    Dog dog1;
    Dog dog2 = dog1;
    dog2.makeSound();

    
    return 0;
}

