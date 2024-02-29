//numbers passed in argument must be less than 10
//output result on stdout
//what errors can occur during execution?
//handle + - / *
//don’t need to manage the brackets or decimal numbers. prints error
#include "RPN.hpp"

bool validateArg(std::string arg)
{

}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

int operation(int op1, int op2, char sign)
{
    int res = 0;

    switch (sign)
    {
    case '+':
        return op1 + op2;
        break;
    case '-':
        return op1 - op2;
        break;
    case '/':
        return op1 / op2;
        break;
    case '*':
        return op1 * op2;
        break;
    }
}

int operate(std::string arg)
{
    std::stack<int> oStack;
    int op1 = 0;
    int op2 = 0;
    int res = 0;
    int i = -1;
    while(arg[++i])
    {
        if(isOperator(arg[i]))
        {
            op2 = oStack.top();
            oStack.pop();
            op1 = oStack.top();
            oStack.pop();
            res = operation(op1, op2, arg[i]);
        }
        else if(!std::isspace(arg[i]))
            oStack.push(std::atoi(std::string(1, arg[i]).c_str()));
    }
}

int RPN(std::string arg)
{
    if(!validateArg(arg))
    {
        std::cerr<<"Error: argument is not valid"<<std::endl;
        return 1;
    }
    int result = 0;
    result = operate(arg);

    std::cout<<result<<std::endl;
    return 0;
}