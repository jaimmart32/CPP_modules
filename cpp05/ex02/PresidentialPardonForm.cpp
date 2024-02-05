#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(std::string &target)
: AForm("PresidentialPardonForm",25,5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &source)
: AForm(source), target(source.target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &source)
{
    if (this != &source)
    {
        this->AForm::operator=(source);
        this->target = source.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string PresidentialPardonForm::getTarget() const
{
    return this->target;
}

const char *PresidentialPardonForm::execute(const Bureaucrat &bur) const
{
    try
    {
        if(!this->getIsSigned())
            throw UnsignedException();
        if(this->getExecGrade() < bur.getGrade())
            throw GradeTooLowException(); 
        std::cout<<this->target<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
        return NULL;
    }
    catch(const UnsignedException& e)
    {
        std::cerr<<e.what()<<std::endl;
        return "form is unsigned";
    }
    catch(const GradeTooLowException& e)
    {
        std::cerr<<e.what()<<std::endl;
        return "bureaucrat's grade is to low to execute form";
    }    
}