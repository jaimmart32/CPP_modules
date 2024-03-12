#include "PmergeMe.hpp"

void fill_containers(int argc, char **argv, std::vector<int> &vNumbers, std::list<int> &lNumbers)
{
    for(int i = 1; i < argc; i++)
    {
        int num = std::stoi(argv[i]);
        vNumbers.push_back(num);
        lNumbers.push_back(num);
    }
}

void display_info(std::vector<int> &vNumbers, std::list<int> &lNumbers)
{
    for(std::vector<int>::iterator it = vNumbers.begin(); it != vNumbers.end(); it++)
        std::cout<<*it<<", ";
    std::cout<<"\n";

    for(std::list<int>::iterator it = lNumbers.begin(); it != lNumbers.end(); it++)
        std::cout<<*it<<", ";
    std::cout<<"\n";
}