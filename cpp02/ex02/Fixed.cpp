#include "Fixed.hpp"

// CONSTRUCTORS

Fixed::Fixed()
: fpn_value(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed_source)
: fpn_value(fixed_source.fpn_value)
{
    //std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
    //std::cout << "Int constructor called" << std::endl;
    this->fpn_value = number * (1 << this->num_frac_bits); // is equivalent to shifting the bits of number to the left by 8 positions and leaving 8 bits for the fractionary part of value 0 because its an int.
}

Fixed::Fixed(const float number)
{
    //std::cout << "Float constructor called" << std::endl;
    this->fpn_value = roundf(number * (1 << this->num_frac_bits));
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

// OPERATOR OVERLOADS

Fixed &Fixed::operator=(const Fixed &fixed_source)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed_source)
        this->fpn_value = fixed_source.getRawBits();
    return *this;
}

// comparison operators

bool    Fixed::operator>(const Fixed &another)
{
    if(this->fpn_value > another.getRawBits())
        return true;
    else
        return false;
}

bool    Fixed::operator<(const Fixed &another)
{
    if(this->fpn_value < another.getRawBits())
        return true;
    else
        return false;
}

bool    Fixed::operator>=(const Fixed &another)
{
    if(this->fpn_value >= another.getRawBits())
        return true;
    else
        return false;
}

bool    Fixed::operator<=(const Fixed &another)
{
    if(this->fpn_value <= another.getRawBits())
        return true;
    else
        return false;
}

bool    Fixed::operator==(const Fixed &another)
{
    if(this->fpn_value == another.getRawBits())
        return true;
    else
        return false;
}

bool    Fixed::operator!=(const Fixed &another)
{
    if(this->fpn_value != another.getRawBits())
        return true;
    else
        return false;
}

// Arithmetic Operators

float   Fixed::operator+(const Fixed &another)
{
    float res = this->toFloat() + another.toFloat();
    return res;
}

float   Fixed::operator-(const Fixed &another)
{
    float res = this->toFloat() - another.toFloat();
    return res;
}

float   Fixed::operator*(const Fixed &another)
{
    float res = this->toFloat() * another.toFloat();
    return res;
}

float   Fixed::operator/(const Fixed &another)
{
    float res = this->toFloat() / another.toFloat();
    return res;
}

// Increment/Decrement Operators

Fixed   &Fixed::operator++(void)
{
    this->fpn_value += 1;
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed aux = *this;
    this->fpn_value += 1;
    return aux;
}

Fixed   &Fixed::operator--(void)
{
    this->fpn_value -= 1;
    return *this;
}

Fixed   Fixed::operator--(int)
{
    Fixed aux = *this;
    this->fpn_value -= 1;
    return aux;
}

std::ostream &operator<<(std::ostream &output_stream, const Fixed &fixed_num)
{
    output_stream << fixed_num.toFloat();
    return output_stream;
}

// OTHER MEMBER FUNCTIONS

Fixed   &Fixed::min(Fixed &fix1, Fixed &fix2)
{
    if(fix1.getRawBits() < fix2.getRawBits())
        return fix1;
    else
        return fix2;
}

const Fixed   &Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
    if(fix1.getRawBits() < fix2.getRawBits())
        return fix1;
    else
        return fix2;
}

Fixed   &Fixed::max(Fixed &fix1, Fixed &fix2)
{
    if(fix1.getRawBits() > fix2.getRawBits())
        return fix1;
    else
        return fix2;
}

const Fixed   &Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
    if(fix1.getRawBits() > fix2.getRawBits())
        return fix1;
    else
        return fix2;
}

int Fixed::getRawBits() const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return this->fpn_value;
}

void    Fixed::setRawBits(const int raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
    this->fpn_value = raw;
}

float   Fixed::toFloat(void) const
{
    return this->fpn_value / (double)(1 << this->num_frac_bits); // this is used to "undo" the multiplication by the power of 2 in the fixed point representation.
}

int Fixed::toInt(void) const
{
    return this->fpn_value / (double)(1 << this->num_frac_bits);
}