#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
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
	}
    {
		WrongAnimal  const *meta = new WrongAnimal();
		WrongAnimal  const *j = new WrongCat();

		std::cout << j->getType() << " " << std::endl;

		j->makeSound(); //will output the cat sound!
		meta->makeSound();

		delete meta;
		delete j;
	}
    return 0;
}

