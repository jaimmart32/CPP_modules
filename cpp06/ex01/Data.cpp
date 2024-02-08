#include "Data.hpp"

Data::Data()
:c('c'), i(42),f(42.2),d(42.2)
{}

Data::Data(const Data &source)
: c(source.c),i(source.i),f(source.f),d(source.d)
{}

Data &Data::operator=(const Data &source)
{
    if(this != &source) 
    {
        this->c =source.c;
        this->i =source.i;
        this->f =source.f;
        this->d =source.d;
    }
    return *this;
}

Data::~Data()
{}