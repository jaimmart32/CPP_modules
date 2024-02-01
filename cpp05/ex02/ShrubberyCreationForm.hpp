#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;
    ShrubberyCreationForm();
public:
    ShrubberyCreationForm(const ShrubberyCreationForm &source);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &source);
    ShrubberyCreationForm(std::string &target);
    ~ShrubberyCreationForm();

    std::string getTarget() const;

    void execute(const Bureaucrat &bur) const;

    class UnopenedException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

#endif