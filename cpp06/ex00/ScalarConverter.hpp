#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

enum data_type
{
    CHAR,INT,FLOAT,DOUBLE,PSEUDO,NONVALID
};

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &source);
    ScalarConverter &operator=(const ScalarConverter &source);
public:
    ~ScalarConverter();
    static void convert(std::string arg);
};

data_type identify_arg(std::string arg);

void manage_pseudo(std::string arg);
void manage_nonvalid();
void manage_char(std::string arg);
void manage_int(std::string arg);
void manage_float(std::string arg);
void manage_double(std::string arg);

bool    convert_to_int(std::string arg);
bool    convert_to_float(std::string arg);
bool    convert_to_double(std::string arg);
#endif