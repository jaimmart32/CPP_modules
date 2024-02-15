#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array
{
private:
    T *array;
    unsigned int len;
public:
    Array()
    {
        this->array = new T[0];
        this->len = 0;
    }

    Array(const Array &source)
    {
        *this = source;
    }


    Array &operator=(const Array &source)
    {
        if(this != &source)
        {
            this->len = source.len;
            this->array = new T[this->len];

            for(unsigned int i = 0; i < this->len; i++)
                this->array[i] = source.array[i];
        }
    }

    ~Array()
    {
        delete[] this->array;
    }


    Array(unsigned int n)
    {
        this->len = n;
        this->array = new T[n];
    }

    unsigned int size() const
    {
        return this->len;
    }

    T &operator[](unsigned int i)
    {
        if(i >= this->len)
            throw std::out_of_range("Out of array boundaries");
        return this->array[i];
    }
};

#endif