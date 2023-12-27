#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon  *weapon;
public:
    HumanB(std::string);
    ~HumanB();
    void    setWeapon(Weapon &weapon);
    void    attack(void);
};

#endif