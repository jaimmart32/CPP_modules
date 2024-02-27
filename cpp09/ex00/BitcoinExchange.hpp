#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

class BitcoinExchange
{
private:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &source);
    BitcoinExchange &operator=(const BitcoinExchange &source);
public:
    ~BitcoinExchange();

    static int show(std::string inputFileName);
};

#endif