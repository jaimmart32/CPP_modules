#ifndef SCRAVTRAP_HPP
#define SCRAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(ScavTrap &source);
    ScavTrap &operator=(const ScavTrap &source);
    ~ScavTrap();

    ScavTrap(std::string Name);

    void    attack(const std::string& target);
    void    guardGate();
};
#endif