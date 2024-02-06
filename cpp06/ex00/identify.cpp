#include "ScalarConverter.hpp"


static data_type num_type(std::string arg)
{
    //npos = non valid position for std::string
    if(arg.find('f') != std::string::npos)
        return FLOAT;
    if(arg.find('.') != std::string::npos)
        return DOUBLE;
    return INT;
}

static bool is_num(std::string arg)
{
    int i = 0;
    int len = arg.length();

    if(i < len && (arg.at(i) == '+' || arg.at(i) == '-'))
        i++;
    if(i < len && std::isdigit(arg.at(i)))
        while(i < len && std::isdigit(arg.at(i)))
            i++;
    else
        return false;
    if(i < len && arg.at(i) == '.')
        i++;
    if(i < len && std::isdigit(arg.at(i)))
        while(i < len && std::isdigit(arg.at(i)))
            i++;
    else
        return false;
    if(i < len && arg.at(i) == 'f')
        i++;
    return i == len;
}

data_type identify_arg(std::string arg)
{
    std::string pseudos[5];
    pseudos[0] = "-inff";
    pseudos[1] = "+inff";
    pseudos[2] = "nan";
    pseudos[3] = "-inf";
    pseudos[4] = "+inf";

    for(int i = 0;i < 5;i++)
        if(arg == pseudos[i])
            return PSEUDO;
    
    if(is_num(arg))
        return num_type(arg);
    if(std::isprint(arg.at(0)) && arg.length() == 1)
        return CHAR;
    return NONVALID;
}