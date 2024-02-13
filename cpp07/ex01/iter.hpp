#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void plus10(T &generic)
{
    generic += 10;
}

template <typename Temp>
void iter(Temp array[], int size, void (*foo)(Temp&))
{
    for(int i = 0; i < size; i++)
        foo(array[i]);
}
/*Temp in the first parameter cannot be a pointer of type (Temp*) because otherwise the Temp
in the third parameter will be a pointer and we want it to be any generic type of data, not
a pointer to any generic data 
iter(T *array, int size, void (*f)(T &)) --->  will not work as expected*/
#endif