#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
protected:
    std::string Name;
    int HitPoints;
    int EnergyPoints;
    int AttackDamage;

public:
    ClapTrap();
    ClapTrap(ClapTrap &source);
    ClapTrap    &operator=(const ClapTrap &source);
    ~ClapTrap();
    
    ClapTrap(std::string Name);

    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

    int getAttackDamage();
};
#endif