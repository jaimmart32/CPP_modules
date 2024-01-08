#include "Fixed.hpp"

Fixed::Fixed()
: fpn_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed_source)
: fpn_value(fixed_source.fpn_value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed_source)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed_source)
        this->fpn_value = fixed_source.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fpn_value;
}

void    Fixed::setRawBits(const int raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fpn_value = raw;
}