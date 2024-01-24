#include "Character.hpp"

Character::Character()
{
    this->name = "NoName";
    for(int i = 0;i < 4; i++)
        this->materia_slots[i] = NULL;
    for(int i = 0;i < 1024; i++)
        this->floor[i] = NULL;
}

Character::Character(const Character &source)
{
    *this = source;
}
//During copy, the Materias of a Character must be deleted before the new ones are added to their inventory?
Character &Character::operator=(const Character &source)
{
    if(this != &source)
    {
        this->name = source.name;
        for(int i = 0; i < 4; i++)
        {
            if(source.materia_slots[i])
                this->materia_slots[i] = source.materia_slots[i]->clone();
            else
                this->materia_slots[i] = NULL;
        }
        for(int i = 0; i < 1024; i++)
        {
            if(source.floor[i])
                this->floor[i] = source.floor[i]->clone();
            else
                this->floor[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    for(int i = 0; i < 4; i++)
    {
        if(this->materia_slots[i])
            delete this->materia_slots[i];
    }
    for(int i = 0; i < 1024; i++)
    {
        if(this->floor[i])
            delete this->floor[i];
    }
}

Character::Character(std::string name)
{
    this->name = name;
    for(int i = 0;i < 4; i++)
        this->materia_slots[i] = NULL;
    for(int i = 0;i < 1024; i++)
        this->floor[i] = NULL;
}

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    for(int i = 0; i < 4; i++)
    {
        if(m && this->materia_slots[i] == NULL)
        {
            this->materia_slots[i] = m->clone();
            break ;
        }
    }
}

void Character::unequip(int idx)
{
    if(this->materia_slots[idx] == NULL)
        return;
    for(int i = 0; i < 1024; i++)
    {
        if(this->floor[i] == NULL)
        {
            this->floor[i] = this->materia_slots[idx];
            this->materia_slots[idx] = NULL;
            break ;
        }
    }
    
}

void Character::use(int idx, ICharacter& target)
{
    if(this->materia_slots[idx])
        this->materia_slots[idx]->use(target);
    else
        std::cout<<"No Materia for slot["<<idx<<"]!"<<std::endl;
}