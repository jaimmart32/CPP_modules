#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(const Cure &source);
    Cure &operator=(const Cure &source);
    ~Cure();

    Cure *clone() const;
    void use(ICharacter &target);

};
#endif