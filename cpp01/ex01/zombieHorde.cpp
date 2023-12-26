#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *p_zombies = new Zombie[N];

    for (int i = 0; i < N; i++)
        p_zombies[i].setName(name);
    
    return p_zombies;
}