#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(42);

    try
    {
        std::vector<int>::iterator result = easyfind(vec, 42);
        std::cout<<"\033[0;32mvalue: "<<*result<<" was foud in vector!\033[0m"<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr<<"\033[0;31mError : "<<e.what()<<"\033[0m"<<std::endl;
    }
    try
    {
        std::vector<int>::iterator result = easyfind(vec, 4);
        std::cout<<"\033[0;32mvalue: "<<*result<<" was foud in vector!\033[0m"<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr<<"\033[0;31mError : "<<e.what()<<"\033[0m"<<std::endl;
    }
    
    std::list<int> my_list;
    my_list.push_back(32);
    my_list.push_back(42);
    my_list.push_back(111);
    my_list.push_back(420);

    try
    {
        std::list<int>::iterator result2 = easyfind(my_list, 32);
        std::cout<<"\033[0;32mvalue: "<<*result2<<" was foud in list!\033[0m"<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr<<"\033[0;31mError : "<<e.what()<<"\033[0m"<<std::endl;
    }
    try
    {
        std::list<int>::iterator result2 = easyfind(my_list, 999);
        std::cout<<"\033[0;32mvalue: "<<*result2<<" was foud in list!\033[0m"<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr<<"\033[0;31mError : "<<e.what()<<"\033[0m"<<std::endl;
    }
}