#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int fpn_value;
    static const int num_frac_bits = 8;
public:
    // Default Constructor
    Fixed();
    // Copy Constructor
    Fixed(const Fixed &fixed_source);
    // Copy Assignment Operator Overload
    Fixed &operator=(const Fixed &fixed_source);

    ~Fixed();

    Fixed(const int number);
    Fixed(const float number);

    int getRawBits( void ) const;
    void    setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &output_stream, const Fixed &fixed_num);
#endif