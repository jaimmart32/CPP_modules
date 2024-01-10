#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("Ratata");
    ScavTrap b("Caniche");

    for(int i = 1; i <= 7; i++)
    {
        std::cout << "Round " << i << " *******************************************************" << std::endl;
        a.attack("Caniche");
        if(i != 7)
            b.takeDamage(a.getAttackDamage());

        b.attack("Ratata");
        a.takeDamage(b.getAttackDamage());

        if(i == 1)
        {
            a.beRepaired(10);
            b.beRepaired(42);
        }
        if(i == 5)
        {
            a.guardGate();
            b.guardGate();
        }
    }
    std::cout << "*********************************************************************" << std::endl;
    std::cout << "Caniche won, it repaired more HP and destroyed its oponent before!" << std::endl;
}