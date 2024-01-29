#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat bossy("boss", -3);
    Bureaucrat slave("slave",145);

        for(int i = 0; i < 7; i++)
            slave.decrementGrade();

    std::cout<<slave.getName()<<"'s grade: "<<slave.getGrade()<<std::endl;
    std::cout<<slave<<std::endl;
    return 0;
}