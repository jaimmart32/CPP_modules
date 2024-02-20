#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <ctime>

class Span
{
private:
    unsigned int max_len;
    std::vector<int> vec;
    Span();
public:
    Span(const unsigned int N);
    Span(const Span &source);
    Span &operator=(const Span &source);
    ~Span();

    void addNumber(int value);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan();
    int longestSpan();

    void show();
};
#endif