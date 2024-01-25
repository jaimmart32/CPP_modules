#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

class Character : public ICharacter
{
private:
    AMateria *materia_slots[4];
    AMateria *floor[1024];
    std::string name;
public:
    Character();
    Character(const Character &source);
    Character &operator=(const Character &source);
    ~Character();

    Character(std::string name);

    //Inherited Mandatory methods
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};
#endif