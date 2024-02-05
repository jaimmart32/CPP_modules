#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::string tom = "poorTommy";
    std::string home = "home";
    std::string bad = "thug";

    Bureaucrat bossy("boss", 4);
    Bureaucrat slave("slave",146);
    Bureaucrat alaparic("Alex",69);

    Intern young;
    AForm *forms[3];
    AForm *samaritan;

    std::cout<<"1**********************************************"<<std::endl;
    samaritan = young.makeForm("becomeRich", tom);
    
    forms[0] = young.makeForm("ShrubberyCreationForm", tom);
    forms[1] = young.makeForm("RobotomyRequestForm", tom);
    forms[2] = young.makeForm("PresidentialPardonForm", tom);

    std::cout<<*forms[0]<<std::endl;
    std::cout<<*forms[1]<<std::endl;
    std::cout<<*forms[2]<<std::endl;

    std::cout<<"2**********************************************"<<std::endl;
    bossy.executeForm(*forms[0]);
    bossy.executeForm(*forms[1]);
    bossy.executeForm(*forms[2]);

    std::cout<<"3**********************************************"<<std::endl;
    slave.signForm(*forms[0]);
    bossy.signForm(*forms[0]);
    alaparic.signForm(*forms[1]);
    bossy.signForm(*forms[2]);

    std::cout<<"4**********************************************"<<std::endl;
    slave.executeForm(*forms[0]);
    alaparic.executeForm(*forms[0]);
    alaparic.executeForm(*forms[1]);
    bossy.executeForm(*forms[1]);
    bossy.executeForm(*forms[2]);

    std::cout<<"5**********************************************"<<std::endl;
    std::cout<<slave<<std::endl;
    std::cout<<bossy<<std::endl;
    std::cout<<alaparic<<std::endl;

    std::cout<<"**********************************************"<<std::endl;
    if(samaritan)
        delete samaritan;
    delete forms[0];
    delete forms[1];
    delete forms[2];
    return 0;
}