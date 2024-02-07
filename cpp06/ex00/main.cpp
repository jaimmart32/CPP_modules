#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
		std::cerr << "\033[0;31mError: more than 1 argument\033[0m" << std::endl;
	else
		ScalarConverter::convert(argv[1]);
	return 0;
}

/*./ScalarConverter 42.999999
char: '*'
int: 42
float: 43f
double: 43

check if float doesn't have . and if it doesn't add .0

*/