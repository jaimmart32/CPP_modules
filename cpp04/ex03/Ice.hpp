#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice &source);
    Ice &operator=(const Ice &source);
    ~Ice();

    Ice *clone() const;
    void use(ICharacter &target);

};
#endif