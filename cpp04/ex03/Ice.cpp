#include "Ice.hpp"

Ice::Ice()
{
    this->type = "ice";
}

Ice::Ice(const Ice &source)
: AMateria(source)
{
    *this = source;
}

Ice &Ice::operator=(const Ice &source)
{
    (void)source;
    this->type = "ice";
    return *this;
}

Ice::~Ice()
{
}

Ice *Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter &target)
{
    std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}