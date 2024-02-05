#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool    is_signed;
    const int sign_grade;
    const int exec_grade;
public:
    AForm();
    AForm(const AForm &source);
    AForm &operator=(const AForm &source);
    virtual ~AForm();

    AForm(std::string name,int sign_grade,int exec_grade);

    const char *beSigned(const Bureaucrat &bur);
    virtual const char *execute(Bureaucrat const & executor) const = 0;

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
    class UnsignedException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &output, const AForm &form);

#endif