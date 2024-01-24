#include "Dog.hpp"

Dog::Dog()
: Animal()
{
    std::cout<<"\033[2;30mDefault constructor called: Dog\033[0m"<<std::endl;
    this->type = "Dog";
    this->dogBrain = new Brain();
}

Dog::Dog(const Dog& source)
: Animal()
{
    std::cout<<"\033[2;30mCopy constructor called: Dog\033[0m"<<std::endl;
    this->type = source.type;
    this->dogBrain = new Brain(*source.dogBrain);// Deep Copy
}
Dog  &Dog::operator=(const Dog &source)
{
    if(this != &source)
    {
        this->type = source.type;
        this->dogBrain = new Brain(*source.dogBrain);// Deep copy
    }
    return *this;
}

Dog::~Dog()
{
    std::cout<<"\033[2;30mDestructor called: Dog\033[0m"<<std::endl;
    delete this->dogBrain;
}

void    Dog::makeSound() const
{
    std::cout<<"Guau guau guay"<<std::endl;
}