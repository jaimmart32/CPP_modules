#include "ScalarConverter.hpp"

void    manage_nonvalid()
{
    std::cerr<<"\033[0;31mError: Non valid argument\033[0m"<<std::endl;
}

void    manage_pseudo(std::string arg)
{
    std::cout<<"char: impossible"<<std::endl;
    std::cout<<"int: impossible"<<std::endl;
    std::cout<<"float: "<<arg
    <<((arg == "-inf" || arg == "+inf" || arg == "nan") ? "f" : "")
    <<std::endl;
    std::cout<<"double: "
    <<((arg == "-inff" || arg == "+inff") ? arg.substr(0, arg.length()-1) : arg)
    <<std::endl;
}

void    manage_char(std::string arg)
{
    int i = static_cast<int>(arg.at(0));
    float f = static_cast<float>(arg.at(0));
    double d = static_cast<double>(arg.at(0));

    std::cout<<"char: '"<<arg<<"'"<<std::endl;
    std::cout<<"int: "<<i<<std::endl;
    std::cout<<"float: "<<f<<".0f"<<std::endl;
    std::cout<<"double: "<<d<<".0"<<std::endl;
}

void    manage_int(std::string arg)
{
    int i = std::atoi(arg.c_str());
    float f = std::atof(arg.c_str());
    double d = std::atof(arg.c_str());
    char c = static_cast<char>(i);

    if(i < 0 || !convert_to_int(arg))
        std::cout<<"char: impossible"<<std::endl;
    else if(std::isprint(c))
        std::cout<<"char: '"<<c<<"'"<<std::endl;
    else
        std::cout<<"char: Non displayable"<<std::endl;
    
    if(convert_to_int(arg))
        std::cout<<"int: "<<i<<std::endl;
    else
        std::cout<<"int: impossible"<<std::endl;

    if(convert_to_float(arg))
        std::cout<<"float: "<<f<<".0f"<<std::endl;
    else
        std::cout<<"float: impossible"<<std::endl;

    if(convert_to_double(arg))
        std::cout<<"double: "<<d<<".0"<<std::endl;
    else
        std::cout<<"double: impossible"<<std::endl;
}

void    manage_float(std::string arg)
{
    int i = std::atoi(arg.c_str());
    float f = std::atof(arg.c_str());
    double d = std::atof(arg.c_str());
    char c = static_cast<char>(i);

    if(i < 0 || convert_to_int(arg))
        std::cout<<"char: impossible"<<std::endl;
    else if(std::isprint(c))
        std::cout<<"char: '"<<c<<"'"<<std::endl;
    else
        std::cout<<"char: Non displayable"<<std::endl;

    if(convert_to_int(arg))
        std::cout<<"int: "<<i<<std::endl;
    else
        std::cout<<"int: impossible"<<std::endl;

    std::cout<<"float: "<<f<<"f"<<std::endl;//check for conversion????
    std::cout<<"double: "<<d<<std::endl;//check for conversion????
}

void    manage_double(std::string arg)
{
    int i = std::atoi(arg.c_str());
    float f = std::atof(arg.c_str());
    double d = std::atof(arg.c_str());
    char c = static_cast<char>(i);

    if(i < 0 || !convert_to_int(arg))
        std::cout<<"char: impossible"<<std::endl;
    else if(std::isprint(c))
        std::cout<<"char: '"<<c<<"'"<<std::endl;
    else
        std::cout<<"char: Non displayable"<<std::endl;

    if(convert_to_int(arg))
        std::cout<<"int: "<<i<<std::endl;
    else
        std::cout<<"int: impossible"<<std::endl;

    std::cout<<"float: "<<f<<"f"<<std::endl;//check for conversion????
    std::cout<<"double: "<<d<<std::endl;//check for conversion????
}
