#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& source)
{
	(void)source;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& source)
{
	(void)source;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string arg)
{
    switch(identify_arg(arg))
    {
        case CHAR:
            manage_char(arg);
            break ;
        case INT:
            manage_int(arg);
            break ;
        case FLOAT:
            manage_float(arg);
            break ;
        case DOUBLE:
            manage_double(arg);
            break ;
        case PSEUDO:
            manage_pseudo(arg);
            break ;
        case NONVALID:
            manage_nonvalid();
            break ;
    }
}