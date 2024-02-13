#include "iter.hpp"
#include <iostream>

int main()
{
    int array[4];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;

    iter(array, 4, plus10);

    std::cout<<"int array[] = ("<<array[0]<<", "<<array[1]<<", "<<array[2]<<", "<<array[3]<<")"<<std::endl;

    char c_array[4];
    c_array[0] = 'a';
    c_array[1] = 'b';
    c_array[2] = 'c';
    c_array[3] = 'd';

    iter(c_array, 4, plus10);

    std::cout<<"\033[0;33mchar array[] = ("<<c_array[0]<<", "<<c_array[1]<<", "<<c_array[2]<<", "<<c_array[3]<<")\033[0m"<<std::endl;

    float f_array[4];
    f_array[0] = 3.5;
    f_array[1] = 7.5;
    f_array[2] = 8.5;
    f_array[3] = 9.5;

    iter(f_array, 4, plus10);

    std::cout<<"\033[0;34mfloat array[] = ("<<f_array[0]<<", "<<f_array[1]<<", "<<f_array[2]<<", "<<f_array[3]<<")\033[0m"<<std::endl;
}