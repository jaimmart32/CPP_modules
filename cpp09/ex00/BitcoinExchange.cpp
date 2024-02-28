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

std::string cleanSpace(std::string str)
{
    std::string cleanStr;
    size_t pos = str.find_first_of(' ');
    if(pos != std::string::npos)
       cleanStr = str.substr(0, pos);
    return cleanStr;
}

bool    validDate(std::string date)
{
    if(date.length() != 10)
        return false;
    int i = -1;
    while(date[++i])
    {
        if(i != 4 && i != 7 && !std::isdigit(date[i]))
            return false;
    }
    return true;
}

bool validAmount(double amount)
{
    if(amount < 0 || amount > 1000)
        return false;
    return true;
}

std::string closestDate(std::map<std::string, double>& btcData, const std::string& date)
{
    std::string closestDate;

    for (std::map<std::string, double>::iterator it = btcData.begin();it != btcData.end();it++)
    {
        if(date >= it->first)
         closestDate = it->first;
    }
    return closestDate;
}



int BitcoinExchange::show(std::string inputFileName)
{
    //Open database file
    std::ifstream dataFile("data.csv");
    if(!dataFile)
    {
        std::cerr<<"\033[0;31mError: couldn't open data.csv\033[0m"<<std::endl;
        return 1;
    }

    //Parse data.csv
    std::map<std::string, double> btcData;
    std::string dbLine;

    while(std::getline(dataFile, dbLine))
    {
        std::istringstream iss(dbLine);
        std::string date;
        double value;

        if(std::getline(iss, date, ',') && iss >> value)
            btcData[date] = value;
        //else
        //    std::cerr<<"\033[0;31mError: invalid line in data.csv\033[0m"<<std::endl;
    }
    dataFile.close();

    //Print std::map to verify
    //for(std::map<std::string, double>::iterator it = btcData.begin(); it != btcData.end(); it++)
    //    std::cout<< "Date: "<<it->first <<", BTC Value: "<<std::fixed<<std::setprecision(2)<<it->second<<std::endl;

    //Open inputfile
    std::ifstream inputFile(inputFileName);
    if(!inputFile)
    {
        std::cerr<<"\033[0;31mError: couldn't open input file\033[0m"<<std::endl;
        return 1;
    }

    //Process each line from inputfile
    std::string line;
    while(std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string dateBuff;
        std::string amountBuff;

        //Clean whitespaces
        //iss >> std::ws;

        //Extract date and amount, print result
        if(std::getline(iss, dateBuff,  '|') && std::getline(iss >> std::ws, amountBuff))
        {
            dateBuff = cleanSpace(dateBuff);
            double btcAmount = 0.0;
            std::cout<<dateBuff<<"**"<<amountBuff<<std::endl;
            if(!validDate(dateBuff))
            {
                std::cerr<<"Error: invalid date format"<<std::endl;
                continue;
            }
            try
            {
                btcAmount = std::stod(amountBuff);
            }
            catch(std::exception &e)
            {
                std::cerr<<"Error: invalid btc amount"<<std::endl;
                continue;
            }
            if(!validAmount(btcAmount))
            {
                std::cerr<<"Error: invalid btc amount"<<std::endl;
                continue;
            }
            dateBuff = closestDate(btcData, dateBuff);
            std::map<std::string, double>::iterator it = btcData.find(dateBuff);
            if(it == btcData.end())
            {
                std::cerr<<"Error: date is before bitcoin"<<std::endl;
                continue;
            }
            double totalValue = it->second * btcAmount;
            std::cout<<dateBuff<<" => "<<std::fixed<<std::setprecision(2)<<btcAmount<<" = "<<totalValue<<std::endl;
        }
        else
            std::cerr<<"Error: invalid format for this line"<<std::endl;
    }
    inputFile.close();

    return 0;
}