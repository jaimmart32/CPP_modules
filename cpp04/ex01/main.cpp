#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

std::cout<<"***********************************************************"<<std::endl;

const WrongAnimal* reta = new WrongAnimal();
const WrongAnimal* c = new WrongCat();
std::cout << reta->getType() << " " << std::endl;
std::cout << c->getType() << " " << std::endl;
c->makeSound(); //will not output the cat sound beccause the method is not virtual!
reta->makeSound();

delete j;
delete i;
delete meta;
delete c;
delete reta;
return 0;
}