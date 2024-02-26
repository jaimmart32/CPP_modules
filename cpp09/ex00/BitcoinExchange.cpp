#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &source)
{
    (void)source;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &source)
{
    (void)source;
    return *this;
}

int BitcoinExchange::show(std::string inputFileName)
{
    //Error at opening
    std::ifstream inputFile(inputFileName);
    if(!inputFile)
    {
        std::cerr<<"\033[0;31mError: couldn't open input file\033[0m"<<std::endl;
        return 1;
    }
    std::ifstream dataFile("data.csv");
    if(!dataFile)
    {
        std::cerr<<"\033[0;31mError: couldn't open data.csv\033[0m"<<std::endl;
        return 1;
    }

    //Parse data.csv
    std::map<std::string, double> btcData;
    std::string line;

    while(std::getline(dataFile, line))
    {
        std::istringstream iss(line);
        std::string date;
        double value;

        if(std::getline(iss, date, ',') && iss >> value)
            btcData[date] = value;
        else
            std::cerr<<"\033[0;31mError: invalid line in data.csv\033[0m"<<std::endl;
    }
    dataFile.close();

    //Print std::map to verify
    for(std::map<std::string, double>::iterator it = btcData.begin(); it != btcData.end(); it++)
        std::cout<< "Date: "<<it->first <<", BTC Value: "<<std::fixed<<std::setprecision(2)<<it->second<<std::endl;

    inputFile.close();
    return 0;
}