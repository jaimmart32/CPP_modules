#include "PmergeMe.hpp"

/*A vector is faster at random access to its elements using indexes and a list is faster at adding and removing elements.

Since the algorithm used does not add or remove elements, it only accesses them, the list always loses in performance*/

bool validate_args(int argc, char **argv)
{
    for(int i = 1; i < argc; i++)
    {
        int num;
        try
        {
            num = std::stoi(argv[i]);
        }
        catch(const std::exception& e)
        {
            return false;
        }
        if(num < 0) 
            return false;
    }
    return true;
}

void fill_containers(int argc, char **argv, std::vector<int> &vNumbers, std::list<int> &lNumbers)
{
    for(int i = 1; i < argc; i++)
    {
        int num = std::stoi(argv[i]);
        vNumbers.push_back(num);
        lNumbers.push_back(num);
    }
}

void before_display_info(std::vector<int> &vNumbers, std::list<int> &lNumbers)
{
    std::cout<<"***Before***\n";

    std::cout<<"Vector: ";
    for(std::vector<int>::iterator it = vNumbers.begin(); it != vNumbers.end(); it++)
        std::cout<<*it<<(std::next(it) == vNumbers.end() ? "" : ", ");
    std::cout<<"\n";

    std::cout<<"List: ";
    for(std::list<int>::iterator it = lNumbers.begin(); it != lNumbers.end(); it++)
        std::cout<<*it<<(std::next(it) == lNumbers.end() ? "" : ", ");
    std::cout<<"\n";
}

void after_display_info(std::vector<int> &vNumbers, std::list<int> &lNumbers, double v_duration, double l_duration)
{
    std::cout<<"***After***\n";

    std::cout<<"Vector: ";
    for(std::vector<int>::iterator it = vNumbers.begin(); it != vNumbers.end(); it++)
        std::cout<<*it<<(std::next(it) == vNumbers.end() ? "" : ", ");
    std::cout<<"\n";

    std::cout<<"List: ";
    for(std::list<int>::iterator it = lNumbers.begin(); it != lNumbers.end(); it++)
        std::cout<<*it<<(std::next(it) == lNumbers.end() ? "" : ", ");
    std::cout<<"\n";

    std::cout<<"Time to process with std::vector: "<<v_duration<<" us"<<std::endl;
    std::cout<<"Time to process with std:list: "<<l_duration<<" us"<<std::endl;
}

// VECTOR ALGORITHM (array indexes)

void insertionSort(std::vector<int> &numbers, int start, int end)
{
    for(int i = start + 1; i < end; i++)
    {
        int key = numbers[i];
        int j = i - 1;
        //moves larger numbers to the right
        while(j >= start && numbers[j] > key)
        {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = key;//inserts key value to the left of values greater than it
    }
}

void merge(std::vector<int> &numbers, int left, int middle, int right)
{
    //numbers of elements needed for each temporal vector(if odd number of elements 1 more for L)
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
        insertionSort(numbers, left, right + 1);
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

//LIST ALGORITHM (list iterators)

void l_insertionSort(std::list<int> &numbers, std::list<int>::iterator start, std::list<int>::iterator end)
{
    for(std::list<int>::iterator it = std::next(start); it != end; it++)
    {
        int key = *it;
        std::list<int>::iterator j = std::prev(it);
        while(j != std::prev(numbers.begin()) && *j > key)
        {
            *std::next(j) = *j;
            j--;
        }
        *std::next(j) = key;
    }
}

void l_merge(std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right)
{
    std::list<int> L(left, std::next(middle));
    std::list<int> R(std::next(middle), std::next(right));

    std::list<int>::iterator i = L.begin(), j = R.begin(), k = left;
    while(i != L.end() && j != R.end())
    {
        if(*i <= *j)
        {
            *k = *i;
            i++;
        }
        else
        {
            *k = *j;
            j++;
        }
        k++;
    }

    while( i != L.end())
    {
        *k = *i;
        i++;
        k++;
    }

    while(j != R.end())
    {
        *k = *j;
        j++;
        k++;
    }
}

void l_mergeInsertionSortCall(std::list<int> &numbers, std::list<int>::iterator left, std::list<int>::iterator right, int k)
{
    if(std::distance(left, right) <= k)
        l_insertionSort(numbers, left, std::next(right));
    else
    {
        std::list<int>::iterator middle = std::next(left, std::distance(left, right) / 2);
        l_mergeInsertionSortCall(numbers, left, middle, k);
        l_mergeInsertionSortCall(numbers, middle, right, k);
        l_merge(left, middle, right);
    }
}

void l_mergeInsertionSort(std::list<int> &numbers, int insertion_limit)
{
    l_mergeInsertionSortCall(numbers, numbers.begin(), std::prev(numbers.end()), insertion_limit);
}