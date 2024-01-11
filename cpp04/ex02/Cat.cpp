#include "Cat.hpp"

Cat::Cat()
: Animal()
{
    std::cout<<"\033[2;30mDefault constructor called: Cat\033[0m"<<std::endl;
    this->type = "Cat";
    this->catBrain = new Brain();
}

Cat::Cat(const Cat &source)
: Animal()
{
    std::cout<<"\033[2;30mCopy constructor called: Cat\033[0m"<<std::endl;
    this->type = source.type;
    this->catBrain = new Brain(*source.catBrain);
}
Cat  &Cat::operator=(const Cat &source)
{
    if(this != &source)
    {
        this->type = source.type;
        this->catBrain = new Brain(*source.catBrain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout<<"\033[2;30mDestructor called: Cat\033[0m"<<std::endl;
    delete this->catBrain;
}

void    Cat::makeSound() const
{
    std::cout<<"Miau miau mahou"<<std::endl;
}