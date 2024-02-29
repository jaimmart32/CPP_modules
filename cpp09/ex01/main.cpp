#include "RPN.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
        return std::cerr<<"Error: invalid number of arguments"<<std::endl, 1;
    if(!RPN(argv[1]))
        return 1;
}