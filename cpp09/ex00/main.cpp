#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cerr<<"\033[0;31mError: need 1 file as argument\033[0m"<<std::endl;
        return(1);
    }

    if (BitcoinExchange::show(argv[1]))
        return 1;
    return 0;
}