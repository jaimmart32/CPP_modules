#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
    const std::string name;
    int grade;
    Bureaucrat();
public:
    Bureaucrat(const Bureaucrat &source);
    Bureaucrat &operator=(const Bureaucrat &source);
    ~Bureaucrat();

    Bureaucrat(std::string name, int grade);

    std::string   getName() const;
    int     getGrade() const;
    void    incrementGrade();
    void    decrementGrade();
    void    signForm(AForm &form);
    void    executeForm(AForm const & form);

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

std::ostream    &operator<<(std::ostream &out_stream, const Bureaucrat &bur);

#endif