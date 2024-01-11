#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
: type("Undefined")
{
    std::cout<<"\033[2;30mDefault constructor called: WrongAnimal\033[0m"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& source)
{
    std::cout<<"\033[2;30mCopy constructor called: WrongAnimal\033[0m"<<std::endl;
    this->type = source.type;
}
WrongAnimal  &WrongAnimal::operator=(const WrongAnimal &source)
{
    if(this != &source)
        this->type = source.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout<<"\033[2;30mDestructor called: WrongAnimal\033[0m"<<std::endl;
}

void    WrongAnimal::makeSound() const
{
    std::cout<<"Undefined sound"<<std::endl;
}

const std::string &WrongAnimal::getType() const
{
    return this->type;
}