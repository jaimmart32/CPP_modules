#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data test;
    Data *d_ptr = &test;
    Data *result = 0;

    std::cout<<"Data ptr: "<<d_ptr<<std::endl;

    uintptr_t uint_ptr = Serializer::serialize(d_ptr);

    result = Serializer::deserialize(uint_ptr);
    
    std::cout<<"address after serialize and deserialize: "<<result<<std::endl;

    if(d_ptr == result)
        std::cout<<"\033[32mConversion was successfull\033[0m"<<std::endl;
    
    return 0;
}