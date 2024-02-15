#include "Array.hpp"

int main()
{
    Array<char> str(5);

    for(unsigned int i = 0;i < str.size(); i++)
        str[i] = 'a' + i;
    std::cout<<"str: ";
    for(unsigned int i = 0; i < str.size(); i++)
        std::cout<<str[i];
    std::cout<<std::endl;

    std::cout<<"*****************************************"<<std::endl;
    Array<float> floatArr(4);

    for(unsigned int i = 0; i < floatArr.size(); i++)
        floatArr[i] = i + 0.5;
    std::cout<<"floatArr: ";
    for(unsigned int i = 0; i < floatArr.size(); i++)
        std::cout<<floatArr[i]<<",";
    std::cout<<std::endl;

    std::cout<<"*****************************************"<<std::endl;
    Array<std::string> stringArr(3);

    for(unsigned int i = 0; i < stringArr.size(); i++)
        stringArr[i] = "string";
    std::cout<<"stringArr: "<<std::endl;
    for(unsigned int i = 0; i < stringArr.size(); i++)
        std::cout<<stringArr[i]<<std::endl;
    
    std::cout<<"*****************************************"<<std::endl;
    try
    {
        std::cout<<str[8];

    }
    catch(std::exception &e)
    {
        std::cerr<<"\033[0;31mError: "<<e.what()<<"\033[0m"<<std::endl;
    }
}