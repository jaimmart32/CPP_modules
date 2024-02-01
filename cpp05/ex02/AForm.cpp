#include "AForm.hpp"

AForm::AForm()
: name("Undefined"), is_signed(false),
  sign_grade(150),exec_grade(150)
{
}

AForm::AForm(const AForm &source)
: name(source.name),is_signed(source.is_signed),
  sign_grade(source.sign_grade),exec_grade(source.exec_grade)
{
}

AForm &AForm::operator=(const AForm &source)
{
    if(this != &source)
    {
        this->is_signed = source.is_signed;
    }
    return *this;
}

AForm::~AForm()
{
}

AForm::AForm(std::string name, int sign_grade, int exec_grade)
: name(name),is_signed(false),sign_grade(sign_grade),exec_grade(exec_grade)
{
    try
    {
        if(sign_grade > 150 || exec_grade > 150)
            throw GradeTooLowException();
        else if(sign_grade < 1 || exec_grade < 1)
            throw GradeTooHighException();
    }
    catch(const std::exception& e)
    {
        std::cerr<<e.what()<<std::endl;
    }
}

const char  *AForm::beSigned(const Bureaucrat &bur)
{
    try
    {
        if(bur.getGrade() < 1)
            throw GradeTooHighException();
        if(bur.getGrade() <= this->getSignGrade())
        {
            this->is_signed = true;
            return NULL;
        }
        else
            throw GradeTooLowException();
    }
    catch(const GradeTooLowException& e)
    {
        std::cerr<<e.what()<<std::endl;
        return "its grade is too low to sign it";
    }
    catch(const GradeTooHighException& e)
    {
        std::cerr<<e.what()<<std::endl;
        return "its grade is too high to be an official Bureaucrat!";
    }
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->is_signed;
}

int AForm::getSignGrade() const
{
    return this->sign_grade;
}

int AForm::getExecGrade() const
{
    return this->exec_grade;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "\033[0;31mError: its grade is too high\033[0m";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "\033[0;31mError: its grade is too low\033[0m";
}

const char *AForm::UnsignedException::what()const throw()
{
    return "\033[0;31mError: it has not been signed\033[0m";
}

std::ostream &operator<<(std::ostream &output, const AForm &form)
{
    output<<"Form "<<form.getName()<<": "<<(form.getIsSigned() ? "is" : "isn't")
    <<" signed, requires grade "<<form.getSignGrade()<<" to sign and grade "
    <<form.getExecGrade()<<" to execute.";

    return output;
}