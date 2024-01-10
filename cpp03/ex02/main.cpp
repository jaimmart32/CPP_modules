#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ScavTrap a("Waste");
    FragTrap b("Supreme");

    for(int i = 1; i <= 5; i++)
    {
        std::cout << "Round " << i << " *******************************************************" << std::endl;
        a.attack("Supreme");
        if(i != 5)
            b.takeDamage(a.getAttackDamage());

        b.attack("Waste");
        a.takeDamage(b.getAttackDamage());

        if(i == 1)
        {
            a.beRepaired(10);
            b.beRepaired(42);
        }
        if(i == 5)
        {
            b.highFivesGuys();
            a.guardGate();
        }
    }
    std::cout << "***************************************************************" << std::endl;
    std::cout << "Clearly FragTrap is superior, it has more attack damage!" << std::endl;
}