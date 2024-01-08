#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int fpn_value;
    static const int num_frac_bits = 8; // A static variable of a class is data common to all instances of this class.
public:
    // Default Constructor
    Fixed();
    // Copy Constructor
    Fixed(const Fixed &fixed_source);
    // Copy Assignment Operator Overload
    Fixed &operator=(const Fixed &fixed_source);
    ~Fixed();
    int getRawBits( void ) const; //const after a function declaration means it will not change the state of the object
    void    setRawBits( int const raw );
};

#endif