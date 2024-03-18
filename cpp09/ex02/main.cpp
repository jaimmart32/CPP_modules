#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if(argc < 2)
        return std::cerr<<"\033[0;31mError: No arguments entered\033[0m"<<std::endl, 1;
    if(!validate_args(argc, argv))
        return std::cerr<<"\033[0;31mError: onlly positive integers allowed\033[0m"<<std::endl, 1;

    std::vector<int> vNumbers;
    std::list<int> lNumbers;

    fill_containers(argc, argv, vNumbers, lNumbers);
    before_display_info(vNumbers, lNumbers);

    std::clock_t start_time = std::clock();
    mergeInsertionSort(vNumbers, 5);
    std::clock_t end_time = std::clock();
    double vector_duration = ((end_time - start_time) / (double)CLOCKS_PER_SEC) *  1000000;//secs * 1m for us

    start_time = std::clock();
    l_mergeInsertionSort(lNumbers, 5);
    end_time = std::clock();
    double list_duration = ((end_time - start_time) / (double)CLOCKS_PER_SEC) *  1000000;

    after_display_info(vNumbers, lNumbers, vector_duration, list_duration);

    return 0;
}