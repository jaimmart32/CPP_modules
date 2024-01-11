#include "WrongCat.hpp"

WrongCat::WrongCat()
: WrongAnimal()
{
    std::cout<<"\033[2;30mDefault constructor called: WrongCat\033[0m"<<std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& source)
: WrongAnimal()
{
    std::cout<<"\033[2;30mCopy constructor called: WrongCat\033[0m"<<std::endl;
    this->type = source.type;
}
WrongCat  &WrongCat::operator=(const WrongCat &source)
{
    if(this != &source)
        this->type = source.type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout<<"\033[2;30mDestructor called: WrongCat\033[0m"<<std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout<<"Miau miau mahou"<<std::endl;
}