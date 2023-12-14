#include <iostream>
#include <cctype>

std::string upper(std::string str)
{
    int i = 0;
    std::string strup;
    while(str[i])
    {
        strup += std::toupper(str[i]);
        i++;
    }
    return strup;
}

int main(int argc, char **argv)
{
    int i = 0;
    while(++i < argc)
    {
        //prints things chacho
        if(i == argc - 1)
            std::cout << upper(argv[i]) << std::endl;
        else
            std::cout << upper(argv[i]) << ' ';

    }
    if(argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}