#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat bossy("boss", 33);
    Bureaucrat slave("slave",145);
    Bureaucrat wrong("hacker",-32);

    std::cout<<"**********************************************"<<std::endl;
    Form purchase("purchase", 140, 100);
    Form report("report", 145, 100);
    std::cout<<purchase<<std::endl;
    std::cout<<report<<std::endl;

    std::cout<<"**********************************************"<<std::endl;
    bossy.signForm(purchase);
    slave.signForm(purchase);

    std::cout<<"**********************************************"<<std::endl;
    bossy.signForm(report);
    slave.signForm(report);
    wrong.signForm(report);

    std::cout<<"**********************************************"<<std::endl;
    std::cout<<slave<<std::endl;
    std::cout<<bossy<<std::endl;

    std::cout<<"**********************************************"<<std::endl;
    std::cout<<purchase<<std::endl;
    std::cout<<report<<std::endl;
    return 0;
}