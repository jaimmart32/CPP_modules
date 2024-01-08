#include "Fixed.hpp"

/*int main()
{
    Fixed a(42.42f);
    Fixed b(50.5f);
    Fixed c(a);
    Fixed d;
    Fixed e(3);
    Fixed f(2);
    Fixed g;

    //Comparison
    if (b > a)
        std::cout << "b is greater than a" << std::endl;
    if(a < b)
        std::cout << "a is smaller than b" << std::endl;
    if(a >= c && b >= c)
        std::cout << "a is greater or equal to c, and b to c" << std::endl;
    if(a <= c && c <= b)
        std::cout << "a is smaller or equal to c, and c to b" << std::endl;
    if(a == c && b != c)
        std::cout << "a is equal to c, b is not equal to c" << std::endl;
    // Arithmetic
    d = a + b;
    std::cout << "a + b = " << d << std::endl;
    d = b - a;
    std::cout << "b - a = " << d << std::endl;
    d = e * f;
    std::cout << "e * f = " << d << std::endl;
    d = e / f;
    std::cout << "e / f = " << d << std::endl;
    // Increment/Decrement
    std::cout << "++g = " << ++g << std::endl;
    std::cout << "g++ = " << g++ << std::endl;
    std::cout << "g = " << g << std::endl;
    std::cout << "--g = " << --g << std::endl;
    std::cout << "g-- = " << g-- << std::endl;
    std::cout << "g = " << g << std::endl;

    //min/max
    std::cout << Fixed::max(e, f) << std::endl;
    std::cout << e.max(e, f) << std::endl;
    std::cout << Fixed::min(e, f) << std::endl;
    return 0;
}*/

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}