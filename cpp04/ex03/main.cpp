#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

// void    leaks(void)
// {
//     system("leaks Sorcerers");
// }

int main()
{
//    atexit(leaks);
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());

ICharacter* jimmy = new Character("jimmy");

AMateria* tmp;
tmp = src->createMateria("ice");
jimmy->equip(tmp);
delete tmp;

tmp = src->createMateria("cure");
jimmy->equip(tmp);
jimmy->equip(tmp);
delete tmp;

tmp = src->createMateria("ice");
ICharacter* bob = new Character("bob");
bob->equip(tmp);
delete tmp;

bob->unequip(0);
tmp = src->createMateria("cure");
bob->equip(tmp);
delete tmp;

std::cout<<"**************************************"<<std::endl;
jimmy->use(0, *bob);
jimmy->use(1, *bob);
jimmy->use(3, *bob);
std::cout<<"**************************************"<<std::endl;
bob->use(0, *jimmy);
bob->use(1, *jimmy);

delete bob;
delete jimmy;
delete src;

return 0;
}