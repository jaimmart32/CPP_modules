#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(const AMateria &source)
{
    if(this != &source)
        this->type = source.type;
}

AMateria &AMateria::operator=(const AMateria &source)
{
    if(this != &source)
        this->type = source.type;
    return *this;
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const std::string &type)
{
    this->type = type;
}

std::string const &AMateria::getType() const
{
    return this->type;
}

void    AMateria::use(ICharacter &target)
{
    std::cout << "AMateria used on " << target.getName() << std::endl;
}