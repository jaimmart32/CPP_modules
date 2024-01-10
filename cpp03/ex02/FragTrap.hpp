#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(FragTrap &source);
    FragTrap &operator=(const FragTrap &source);
    ~FragTrap();

    FragTrap(std::string Name);

    void    attack(const std::string& target);
    void    highFivesGuys();
};
#endif