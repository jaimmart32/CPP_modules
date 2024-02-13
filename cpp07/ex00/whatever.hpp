#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

/*This is a template declaration that indicates that the swap function
is a template that takes a type parameter called Temp. The typename keyword
is used to specify a generic type, which can be any valid data type in C++*/
template <typename Temp>
void swap(Temp &a, Temp &b)
{
    Temp aux = a;
    a = b;
    b = aux;
}
template <typename Temp>
Temp min(Temp &a, Temp &b)
{
    if(a < b)
        return a;
    else
        return b;
}

template <typename Temp>
Temp max(Temp &a, Temp &b)
{
    if(a > b)
        return a;
    else
        return b;
}

#endif