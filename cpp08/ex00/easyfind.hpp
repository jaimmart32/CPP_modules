#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm> // For std::find
#include <stdexcept> // For std::runtime_error

//typename in the return value of the function is necessary to indicate to
//the compiler that 'T::iterator' is a typename and not an attribute or method
//of a class called T for example. By specifying this it resolves de ambiguity
//of the function's prototype.

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator iter = std::find(container.begin(), container.end(), value);
    if(iter == container.end())// value not found
        throw std::runtime_error("value not found in container");
    return iter;
}

#endif