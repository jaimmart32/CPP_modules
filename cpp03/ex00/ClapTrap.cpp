#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &source)
{
    std::cout << "Copy Constructor called" << std::endl;
    this->Name = source.Name;
    this->HitPoints = source.HitPoints;
    this->EnergyPoints = source.EnergyPoints;
    this->AttackDamage = source.AttackDamage;
}

ClapTrap    &ClapTrap::operator=(const ClapTrap &source)
{
    if(this != &source)
    {
        this->Name = source.Name;
        this->HitPoints = source.HitPoints;
        this->EnergyPoints = source.EnergyPoints;
        this->AttackDamage = source.AttackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "\033[2;30mDestructor Called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string Name)
: Name(Name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "\033[2;30mNot Default Constructor called\033[0m" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if(this->HitPoints > 0 && this->EnergyPoints > 0)
    {
        this->EnergyPoints--;
        std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->Name << " can't attack!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if(this->HitPoints > 0)
    {
        std::cout << "ClapTrap " << this->Name << " has taken " << amount << " points of damage!" << std::endl;
        this->HitPoints -= amount;
    }
    else
        std::cout << "ClapTrap " << this->Name << " can't take more damage, it's destroyed." << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if(this->HitPoints > 0 && this->EnergyPoints > 0)
    {
        this->EnergyPoints--;
        this->HitPoints += amount;
        std::cout << "ClapTrap " << this->Name << " has been repaired and gained " << amount << " hit points!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->Name << " can't be reparired!" << std::endl;
}

int    ClapTrap::getAttackDamage()
{
    return this->AttackDamage;
}