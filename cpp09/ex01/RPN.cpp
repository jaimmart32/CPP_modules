#include "RPN.hpp"

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

bool validateArg(std::string arg)
{
    int i = -1;
    while(arg[++i])
    {
        if(!std::isspace(arg[i]) && !std::isdigit(arg[i]) && !isOperator(arg[i]))
            return false;
        if(std::isdigit(arg[i]) && arg[i + 1] && std::isdigit(arg[i + 1]))
            return false;
    }
    return true;
}

int operation(int op1, int op2, char sign)
{
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
    return 0;
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
            if(oStack.size() < 2)
                throw std::runtime_error("\033[0;31mError: less than 2 operands for operation\033[0m");
            op2 = oStack.top();
            oStack.pop();
            op1 = oStack.top();
            oStack.pop();
            res = operation(op1, op2, arg[i]);
            oStack.push(res);
        }
        else if(!std::isspace(arg[i]))
            oStack.push(std::atoi(std::string(1, arg[i]).c_str()));
    }
    return res;
}

int RPN(std::string arg)
{
    if(!validateArg(arg))
    {
        std::cerr<<"\033[0;31mError: argument is not valid\033[0m"<<std::endl;
        return 1;
    }
    int result = 0;
    try
    {
        result = operate(arg);
        std::cout<<result<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr<<e.what()<<std::endl;
    }
    return 0;
}