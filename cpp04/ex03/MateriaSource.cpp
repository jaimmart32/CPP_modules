#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
        this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &source)
{
    *this = source;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &source)
{
    if(this != &source)
    {
        for(int i = 0; i < 4; i++)
        {
            if(source.materias[i])
                this->materias[i] = source.materias[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
    {
        if(this->materias[i])
            delete materias[i];
    }
}

void    MateriaSource::learnMateria(AMateria* toLearn)
{
    for(int i = 0; i < 4; i++)
    {
        if(toLearn && this->materias[i] == NULL)
        {
            this->materias[i] = toLearn->clone();
            break ;
        }
    }
}
AMateria*   MateriaSource::createMateria(std::string const &target)
{
    AMateria *creation = NULL;

    for(int i = 0; i < 4; i++)
    {
        if(this->materias[i] && this->materias[i]->getType() == target)
        {
            creation = this->materias[i]->clone();
            break ;
        }
    }
    if(creation)
        return creation;
    else
        return 0;
}