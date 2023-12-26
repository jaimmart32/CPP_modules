#include "Zombie.hpp"

void leaks(void)
{
    system("leaks BrainZ");
}

int main()
{
    atexit(leaks);
    Zombie *heapZombie = newZombie("heapZombie");
    heapZombie->announce();
    randomChump("stackZombie");
    delete heapZombie;
    return 0;
}