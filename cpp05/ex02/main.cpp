#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::string tom = "poorTommy";
    std::string home = "home";
    std::string bad = "thug";

    Bureaucrat bossy("boss", 4);
    Bureaucrat slave("slave",146);
    Bureaucrat alaparic("Alex",69);

    std::cout<<"1**********************************************"<<std::endl;
    RobotomyRequestForm robo(tom);
    ShrubberyCreationForm tree(home);
    PresidentialPardonForm unfair(bad);

    std::cout<<robo<<std::endl;
    std::cout<<tree<<std::endl;
    std::cout<<unfair<<std::endl;

    std::cout<<"2**********************************************"<<std::endl;
    bossy.executeForm(tree);
    bossy.executeForm(robo);
    bossy.executeForm(unfair);

    std::cout<<"3**********************************************"<<std::endl;
    slave.signForm(tree);
    bossy.signForm(tree);
    alaparic.signForm(robo);
    bossy.signForm(unfair);

    std::cout<<"4**********************************************"<<std::endl;
    slave.executeForm(tree);
    alaparic.executeForm(tree);
    alaparic.executeForm(robo);
    bossy.executeForm(robo);
    bossy.executeForm(unfair);

    std::cout<<"5**********************************************"<<std::endl;
    std::cout<<slave<<std::endl;
    std::cout<<bossy<<std::endl;
    std::cout<<alaparic<<std::endl;

    std::cout<<"**********************************************"<<std::endl;
    return 0;
}