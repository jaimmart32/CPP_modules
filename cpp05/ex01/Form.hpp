#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool    is_signed;
    const int sign_grade;
    const int exec_grade;
    Form();
public:
    Form(const Form &source);
    Form &operator=(const Form &source);
    ~Form();

    Form(std::string name,int sign_grade,int exec_grade);

    const char *beSigned(const Bureaucrat &bur);

    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &output, const Form &form);

#endif