#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &source)
{
    (void)source;
}

Intern &Intern::operator=(const Intern &source)
{
    (void)source;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string form_name, std::string form_target)
{
    std::string forms[3];//To comply with std=c++98
    forms[0] = "ShrubberyCreationForm";
    forms[1] = "RobotomyRequestForm";
    forms[2] = "PresidentialPardonForm";
    int code = 0;

    for(int i = 0; i < 3; i++)
        if(form_name == forms[i])
        {
            code = i + 1;
            std::cout<<"\033[0;34mIntern creates \033[0m \033[0;34m"<<form_name<<"\033[0m"<<std::endl;
        }
    switch(code)
    {
        case 1:
            return new ShrubberyCreationForm(form_target);
        case 2:
            return new RobotomyRequestForm(form_target);
        case 3:
            return new PresidentialPardonForm(form_target);
    }
    std::cerr<<"\033[0;31mError: Form name doesn't match any form available\033[0m"<<std::endl;
    return NULL;
}