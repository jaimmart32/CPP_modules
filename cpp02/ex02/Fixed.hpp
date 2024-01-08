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
    //Other constructors
    Fixed(const int number);
    Fixed(const float number);
    ~Fixed();

    //Other Operator Overloads
    bool    operator>(const Fixed &another);
    bool    operator<(const Fixed &another);
    bool    operator>=(const Fixed &another);
    bool    operator<=(const Fixed &another);
    bool    operator==(const Fixed &another);
    bool    operator!=(const Fixed &another);

    float   operator+(const Fixed &another);
    float   operator-(const Fixed &another);
    float   operator*(const Fixed &another);
    float   operator/(const Fixed &another);

    Fixed   &operator++(void);
    Fixed   operator++(int);
    Fixed   &operator--(void);
    Fixed   operator--(int);

    //Other Member functions

    static Fixed    &min(Fixed &fix1, Fixed &fix2);
    static const Fixed    &min(const Fixed &fix1, const Fixed &fix2);
    static Fixed    &max(Fixed &fix1, Fixed &fix2);
    static const Fixed    &max(const Fixed &fix1, const Fixed &fix2);


    int getRawBits( void ) const;
    void    setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &output_stream, const Fixed &fixed_num);
#endif