#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void    Harl::complain(std::string level)
{
    int code = -1;
    std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*complain_ptr)(void) = NULL;

    for(int i = 0; i < 4; i++)
        if(level == options[i])
            code = i;
    
    switch (code)
    {
    case 0:
        complain_ptr = &Harl::debug;
        break;
    case 1:
        complain_ptr = &Harl::info;
        break;
    case 2:
        complain_ptr = &Harl::warning;
        break;
    case 3:
        complain_ptr = &Harl::error;
        break;
    default:
        std::cout << UNVALID_MSG << std::endl;
        break;
    }
    if(complain_ptr)
        (this->*complain_ptr)();
}

void    Harl::debug()
{
    std::cout << DEBUG_MSG << std::endl;
}

void    Harl::info()
{
    std::cout << INFO_MSG << std::endl;
}

void    Harl::warning()
{
    std::cout << WARNING_MSG << std::endl;
}

void    Harl::error()
{
    std::cout << ERROR_MSG << std::endl;
}