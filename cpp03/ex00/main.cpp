#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Killer");
    ClapTrap b("Bee");

    for(int i = 1; i <= 10; i++)
    {
        std::cout << "Round " << i << " *******************************************************" << std::endl;
        a.attack("Bee");
        b.takeDamage(a.getAttackDamage());

        b.attack("Killer");
        a.takeDamage(b.getAttackDamage());

        if(i == 1 || i == 9)
        {
            a.beRepaired(10);
            b.beRepaired(42);
        }
    }
    std::cout << "***************************************************************" << std::endl;
    std::cout << "They can't fight anymore, they don't have more energy!" << std::endl;

}