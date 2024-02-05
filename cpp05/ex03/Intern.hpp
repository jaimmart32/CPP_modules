#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
public:
    Intern();
    Intern(const Intern &source);
    Intern &operator=(const Intern &source);
    ~Intern();

    AForm *makeForm(std::string form_name, std::string form_target);
};

#endif