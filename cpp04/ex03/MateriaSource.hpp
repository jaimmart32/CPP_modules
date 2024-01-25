#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <string>

class MateriaSource : public IMateriaSource
{
private:
    AMateria *materias[4];
public:

    MateriaSource();
    MateriaSource(const MateriaSource &source);
    MateriaSource   &operator=(const MateriaSource &source);
    ~MateriaSource();

    //Inherited Mandatory methods
    void    learnMateria(AMateria*);
    AMateria*   createMateria(std::string const & type);
};

#endif 