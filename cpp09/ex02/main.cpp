#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if(argc < 2)
        return std::cerr<<"Error: No arguments entered"<<std::endl, 1;
    //if(!validate_args(argv))
    //    return std::cerr<<"Error: onlly positive integers allowed"<<std::endl, 1;

    std::vector<int> vNumbers;
    std::list<int> lNumbers;

    fill_containers(argc, argv, vNumbers, lNumbers);

    //start = function for time;
    //merge_insertion_sort(vNumbers);
    //end = funtion for time;
    //vector_duration = end - start;

    //start = function for time;
    //merge_insertion_sort(lNumbers);
    //end = funtion for time;
    //list_duration = end - start;

    //display_info(vNumbers, lNumbers, vector_duration, list_duration);
    display_info(vNumbers, lNumbers);

    return 0;
}