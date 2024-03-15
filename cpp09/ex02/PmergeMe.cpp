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

void display_info(std::vector<int> &vNumbers, std::list<int> &lNumbers, double v_duration)
{
    for(std::vector<int>::iterator it = vNumbers.begin(); it != vNumbers.end(); it++)
        std::cout<<*it<<(std::next(it) == vNumbers.end() ? "" : ", ");
    std::cout<<"\n";

    for(std::list<int>::iterator it = lNumbers.begin(); it != lNumbers.end(); it++)
        std::cout<<*it<<(std::next(it) == lNumbers.end() ? "" : ", ");
    std::cout<<"\n";

    std::cout<<"Time to process with std::vector: "<<v_duration<<" us"<<std::endl;
}

void insertionSort(std::vector<int> &numbers, int start, int end)
{
    for(int i = start + 1; i < end; i++)
    {
        int key = numbers[i];
        int j = i - 1;
        while(j >= start && numbers[j] > key)
        {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = key;
    }
}

void merge(std::vector<int> &numbers, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> L(n1), R(n2);//temporal vectors for sort

    //copy numbers into temporal vectors
    for(int i = 0; i < n1; i++)
        L[i] = numbers[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = numbers[middle + 1 + j];
    
    //order by merge
    int i = 0, j = 0, k = left;//i for LVector, j for RVector, k for originalVector
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            numbers[k] = L[i];
            i++;
        }
        else
        {
            numbers[k] = R[j];
            j++;
        }
        k++;
    }

    //if there are numbers left in L after comparing with R
    while(i < n1)
    {
        numbers[k] = L[i];
        i++;
        k++;
    }

    //if there are numbers left in R after comparing with L
    while(j < n2)
    {
        numbers[k] = R[j];
        j++;
        k++;
    }
}

void mergeInsertionSortCall(std::vector<int> &numbers, int left, int right, int k)
{
    if(right - left <= k)// if the range is small enough to use insertion
        insertionSort(numbers, left, right);
    else
    {
        int middle = left + (right - left) / 2;
        mergeInsertionSortCall(numbers, left, middle, k);
        mergeInsertionSortCall(numbers, middle + 1, right, k);
        merge(numbers, left, middle, right);
    }
}

void mergeInsertionSort(std::vector<int> &numbers, int insertion_limit)
{
    mergeInsertionSortCall(numbers, 0, numbers.size() - 1, insertion_limit);
}