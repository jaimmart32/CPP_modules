#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
: type(type)
{
}

Weapon::~Weapon()
{
}

const std::string&  Weapon::getType()
{
    const std::string &typeREF = this->type;
    return typeREF;
}

void    Weapon::setType(std::string newtype)
{
    this->type = newtype;
}