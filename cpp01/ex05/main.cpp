#include "Harl.hpp"

int main()
{
    std::string input;
    Harl Karen;

    Karen.complain("DEBUG");
    Karen.complain("WARNING");
    Karen.complain("INFO");
    Karen.complain("ERROR");
    Karen.complain("KAREN");
    std::cout << "***************************************************" << std::endl;
    std::cout << "Input levels of complaining. To exit, Type: exit" << std::endl;
    std::cout << "***************************************************" << std::endl;
    while(true)
    {
        std::cout << "Input:";
        std::getline(std::cin, input);
        if(std::cin.eof() || input == "exit")
            break;
        Karen.complain(input);
    }
    return 0;
}