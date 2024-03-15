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

    std::clock_t start_time = std::clock();
    //merge_insertion_sort(vNumbers);
    mergeInsertionSort(vNumbers, 5);
    std::clock_t end_time = std::clock();
    double vector_duration = ((end_time - start_time) / (double)CLOCKS_PER_SEC) *  1000;

    //start = function for time;
    //merge_insertion_sort(lNumbers);
    //end = funtion for time;
    //list_duration = end - start;

    //display_info(vNumbers, lNumbers, vector_duration, list_duration);
    display_info(vNumbers, lNumbers, vector_duration);

    return 0;
}