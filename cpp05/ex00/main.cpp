#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat slave("slave",145);
    try
    {
        for(int i = 0; i < 7; i++)
            slave.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    std::cout<<slave.getName()<<"'s grade: "<<slave.getGrade()<<std::endl;
    return 0;
}