#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void    leaks(void)
{
    system("leaks Sorcerers");
}

int main()
{
    atexit(leaks);
    AMateria *ice_mat = new Ice();
    AMateria *cure_mat = new Cure();
    IMateriaSource *source = new MateriaSource();
    source->learnMateria(ice_mat);
    source->learnMateria(cure_mat);
    //source->learnMateria(new Cure());

    ICharacter *me = new Character("me");
    ICharacter *jimmy = new Character("Jimmy");

    me->equip(ice_mat);
    me->use(0, *jimmy);
    jimmy->equip(cure_mat);
    jimmy->equip(cure_mat);

    //rare
    *me = *jimmy;
    me->use(0, *jimmy);

    delete ice_mat;
    delete cure_mat;
    delete me;
    delete jimmy;
    delete source; 
}


/*int main()
{
    atexit(leaks);
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;
return 0;
}*/