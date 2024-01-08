* ACCURACY VS PRECISION

INT: 5/2 = 2 and 4/2 = 2, not precise
FLOAT: 5.0/2.0 = 2.5, precise

INT: 5 is 5, is accurate
FLOAT: 1.0/3.0 = 0.333333 and not 0.333333333..., not accurate

* IEE-754

Is a Standard for Floating-Point Arithmetic used in C++

s=sign bit e=exponent bits m=mantissa bits
seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm
(-1)^S * 1.M * 2^(E - Bias)

* CODE

1. this->fpn_value = number * (1 << this->num_frac_bits);

-This expression is used to shift the bits of number 8 places so we leave
8 bits to represent the fractional part of our fixed point number.
We could just multiply it by 256 but shifting bits to the left is more
efficient in terms of performance than performing direct multiplication by a power of 2. Modern processors can perform shift-left operations very efficiently.

2. float   Fixed::toFloat(void) const
{
    return this->fpn_value / (double)(1 << this->num_frac_bits);
}

-This is done to undo the shifting of bits by 8 positions that we did to
transform it to a fixed point value, becoming again a float.
(double) casting is used to ensure that the division is a floating point operation, since if both operands are integers, the division will be an integer operation.

3. Why we use roundf() when recieving a float as parameter?

this->fpn_value = roundf(number * (1 << this->num_frac_bits));

fpn_value is an int, roundf() helps ensure that the fixed-point value has the proper representation after conversion from a floating-point number, providing more precise rounding to the nearest integer value.

4. Why converting toFloat when we insert the value in the output stream?

-The reason for doing this conversion is that generally when you print a fixed point number, you want the value to be presented in a format that is more familiar and readable to users, which is the floating point format. The toFloat() function performs this conversion. If not done, suppose you have a Fixed object with an internal value represented as 123456 (in fixed point terms, with 8 bits for the fractional part). Without floating point conversion, the output would be 123456 instead of 1234.56.

5. Example of bit representation display.

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    this->fpn_value = roundf(number * (1 << this->num_frac_bits));
}

-Imagine number is 3.5. 3.5 * 256 is 896, 896 in binary is:
"00000000 00000000 00000011 10000000"
if we are using 8 lest significant bits for fractional part:
"00000000 00000000 00000011 . 10000000"
"00000000 00000000 00000011" is 3 in decimal.
". 10000000" is 0.5 in decimal"

We have our fixed point value stored as a const int, with a imaginary "." separating the fractional part from the integral part and when we display it we use toFloat() to shift return it to a float value of 3.5 dividing it by 256 so we display 3.5 instead of 896.
