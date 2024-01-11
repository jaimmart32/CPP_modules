#include "Dog.hpp"

Dog::Dog()
: Animal()
{
    std::cout<<"\033[2;30mDefault constructor called: Dog\033[0m"<<std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& source)
: Animal()
{
    std::cout<<"\033[2;30mCopy constructor called: Dog\033[0m"<<std::endl;
    this->type = source.type;
}
Dog  &Dog::operator=(const Dog &source)
{
    if(this != &source)
        this->type = source.type;
    return *this;
}

Dog::~Dog()
{
    std::cout<<"\033[2;30mDestructor called: Dog\033[0m"<<std::endl;
}

void    Dog::makeSound() const
{
    std::cout<<"Guau guau guay"<<std::endl;
}