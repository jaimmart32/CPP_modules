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

//Adaptar y checkear!!
std::string fechaMasCercana(const std::map<std::string, double>& bitcoinData, const std::string& fecha) {
    double minDiff = std::numeric_limits<double>::infinity();
    std::string fechaMasCercana;

    for (const auto& pair : bitcoinData) {
        double diff = std::difftime(std::stol(fecha), std::stol(pair.first));
        if (diff <= 0 && std::abs(diff) < minDiff) {
            minDiff = std::abs(diff);
            fechaMasCercana = pair.first;
        }
    }

    return fechaMasCercana;
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
            std::cout<<dateBuff<<"**"<<amountBuff<<std::endl;
            if(dateBuff.empty() || amountBuff.empty())
                std::cerr<<"Error: non valid line"<<std::endl;
            double btcAmount = std::stod(amountBuff);
            std::map<std::string, double>::iterator it = btcData.find(dateBuff);
            if(it == btcData.end())
                std::cerr<<"Temporary Error: date not found"<<std::endl;
            double totalValue = it->second * btcAmount;
            std::cout<<dateBuff<<" => "<<std::fixed<<std::setprecision(2)<<btcAmount<<" = "<<totalValue<<std::endl;
        }
        else
            std::cerr<<"Error: getting date and amount of btc"<<std::endl;
    }
    inputFile.close();

    return 0;
}