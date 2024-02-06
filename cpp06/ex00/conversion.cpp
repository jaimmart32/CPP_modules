#include "ScalarConverter.hpp"

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