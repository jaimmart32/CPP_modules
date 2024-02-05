#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class PresidentialPardonForm : public AForm
{
private:
    std::string target;
    PresidentialPardonForm();
public:
    PresidentialPardonForm(const PresidentialPardonForm &source);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &source);
    PresidentialPardonForm(std::string &target);
    ~PresidentialPardonForm();

    std::string getTarget() const;

    const char *execute(const Bureaucrat &bur) const;
};

#endif