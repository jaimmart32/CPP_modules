#include "Cure.hpp"

Cure::Cure()
{
    this->type = "cure";
}

Cure::Cure(const Cure &source)
: AMateria(source)
{
    (void)source;
    this->type = "cure";
}

Cure &Cure::operator=(const Cure &source)
{
    (void)source;
    this->type = "cure";
    return *this;
}

Cure::~Cure()
{
}

Cure *Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter &target)
{
    std::cout<<"* heals "<<target.getName()<<"'s wounds *"<<std::endl;
}