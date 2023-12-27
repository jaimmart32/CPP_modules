#include "Zombie.hpp"

int main()
{
    int N = 10;
    Zombie *zombie_ptr = zombieHorde(N, "Bruce Lee");

    for(int i = 0; i < N; i++)
    {
        zombie_ptr[i].announce();
    }
    delete[] zombie_ptr;
}