#include "Animal.hpp"

Animal::Animal()
: type("Undefined")
{
    std::cout<<"\033[2;30mDefault constructor called: Animal\033[0m"<<std::endl;
}

Animal::Animal(const Animal& source)
{
    std::cout<<"\033[2;30mCopy constructor called: Animal\033[0m"<<std::endl;
    this->type = source.type;
}
Animal  &Animal::operator=(const Animal &source)
{
    if(this != &source)
        this->type = source.type;
    return *this;
}

Animal::~Animal()
{
    std::cout<<"\033[2;30mDestructor called: Animal\033[0m"<<std::endl;
}

const std::string &Animal::getType() const
{
    return this->type;
}