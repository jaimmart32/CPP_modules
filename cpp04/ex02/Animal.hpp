#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

// To make a class abstract and cannot be instantiated directly, you
// need to have at least one pure virtual member function in the class.
class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal& source);
    Animal &operator=(const Animal& source);
    virtual ~Animal();

    virtual void    makeSound() const = 0; // Pure virtual member function
    const std::string &getType() const;
};

#endif