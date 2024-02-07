#include "ScalarConverter.hpp"

/*When a floating number string is too close to its integer value, the conversion returns
  a number without decimal part, but we want to add .0 if needed.*/

bool has_decimal_f(float f)
{
    std::stringstream ss;
    ss << f;
    std::string f_string = ss.str();
    return f_string.find('.') != std::string::npos;
}

bool has_decimal_d(double d)
{
    std::stringstream ss;
    ss << d;
    std::string d_string = ss.str();
    return d_string.find('.') != std::string::npos;
}

/*Using an input string stream to try to extract a valid int into value's buffer will analize 
if it is not possible regardless of what error occurred instead of checking them individually.*/

bool    convert_to_int(std::string arg)
{
    std::istringstream input_stream(arg);
	int value;
	input_stream >> value;
	return !input_stream.fail();
}

bool    convert_to_float(std::string arg)
{
    std::istringstream input_stream(arg);
	float value;
	input_stream >> value;
	return !input_stream.fail();
}

bool    convert_to_double(std::string arg)
{
    std::istringstream input_stream(arg);
	double value;
	input_stream >> value;
	return !input_stream.fail();
}