#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "\033[2;30mDefault Constructor called: ScavTrap\033[0m" << std::endl;
    this->Name = "NoName";
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap &source)
{
    std::cout << "\033[2;30mCopy Constructor called: ScavTrap\033[0m" << std::endl;
    this->Name = source.Name;
    this->HitPoints = source.HitPoints;
    this->EnergyPoints = source.EnergyPoints;
    this->AttackDamage = source.AttackDamage;
}

ScavTrap    &ScavTrap::operator=(const ScavTrap &source)
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

ScavTrap::~ScavTrap()
{
    std::cout << "\033[2;30mDestructor Called: ScavTrap\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string Name)
{
    std::cout << "\033[2;30mNot Default Constructor called: ScavTrap\033[0m" << std::endl;
    this->Name = Name;
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
}

void    ScavTrap::attack(const std::string& target)
{
    if(this->HitPoints > 0 && this->EnergyPoints > 0)
    {
        this->EnergyPoints--;
        std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->Name << " can't attack!" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->Name << " is in guardGate mode!" << std::endl;
}