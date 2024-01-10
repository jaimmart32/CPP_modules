#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "\033[2;30mDefault Constructor called: FragTrap\033[0m" << std::endl;
    this->Name = "NoName";
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
}

FragTrap::FragTrap(FragTrap &source)
{
    std::cout << "\033[2;30mCopy Constructor called: FragTrap\033[0m" << std::endl;
    this->Name = source.Name;
    this->HitPoints = source.HitPoints;
    this->EnergyPoints = source.EnergyPoints;
    this->AttackDamage = source.AttackDamage;
}

FragTrap    &FragTrap::operator=(const FragTrap &source)
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

FragTrap::~FragTrap()
{
    std::cout << "\033[2;30mDestructor Called: FragTrap\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string Name)
{
    std::cout << "\033[2;30mNot Default Constructor called: FragTrap\033[0m" << std::endl;
    this->Name = Name;
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
}

void    FragTrap::attack(const std::string& target)
{
    if(this->HitPoints > 0 && this->EnergyPoints > 0)
    {
        this->EnergyPoints--;
        std::cout << "FragTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "FragTrap " << this->Name << " can't attack!" << std::endl;
}

void    FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->Name << " is requesting a highfive"<< std::endl;
}