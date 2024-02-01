#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string &target)
: AForm("RobotomyRequestForm",72,45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source)
: AForm(source), target(source.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &source)
{
    if (this != &source)
    {
        this->AForm::operator=(source);
        this->target = source.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->target;
}

void RobotomyRequestForm::execute(const Bureaucrat &bur) const
{
    try
    {
        if(!this->getIsSigned())
            throw UnsignedException();
        if(this->getExecGrade() < bur.getGrade())
            throw GradeTooLowException();
        srand(time(0));// to generate diferent random numbers per execution.
        if(rand() % 2)
        {
            std::cout<<"**UK drilling noises!**"<<std::endl;
            std::cout<<this->getTarget()<<"'s robotomy succeded!"<<std::endl;
        }
        else
            std::cout<<this->getTarget()<<"'s robotomy failed :("<<std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() <<std::endl;
    }
    
}