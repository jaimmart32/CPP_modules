#include "RPN.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
        return std::cerr<<"\033[0;31mError: invalid number of arguments\033[0m"<<std::endl, 1;
    if(!RPN(argv[1]))
        return 1;
    return 0;
}