#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &source)
{
    *this = source;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source)
{
    if(this != &source)
    {
        if(source.grade > 150)
            throw GradeTooLowException();
        else if(source.grade < 1)
            throw GradeTooHighException();
        this->grade = source.grade;

    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, int grade)
: name(name)//name is const so it can only be changed in inicialization
{
    if(grade > 150)
        throw GradeTooLowException();
    else if(grade < 1)
        throw GradeTooHighException();
    this->grade = grade;
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void    Bureaucrat::incrementGrade()
{
    if(this->grade - 1 < 1)
        throw GradeTooHighException();
    else
        this->grade--;
}

void    Bureaucrat::decrementGrade()
{
    if(this->grade + 1 > 150)
        throw GradeTooLowException();
    else
        this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "\033[0;31mError: Grade too high\033[0m";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "\033[0;31mError: Grade too low\033[0m";
}
