#include "Span.hpp"

Span::Span()
: max_len(0)
{}

Span::Span(const unsigned int N)
: max_len(N)
{
}

Span::Span(const Span &source)
{
    *this = source;
}

Span &Span::operator=(const Span &source)
{
    if(this != &source)
    {
        this->max_len = source.max_len;
        vec.clear();
        for(std::vector<int>::const_iterator iter = source.vec.begin(); iter != source.vec.end(); ++iter)
            this->vec.push_back(*iter);
    }
    return *this;
}

Span::~Span(){}

void Span::addNumber(int value)
{
    if(this->vec.size() == this->max_len)
        throw std::runtime_error("Max length for Span reached");
    this->vec.push_back(value);
}

int Span::shortestSpan()
{
    if(vec.size() < 2)
        throw std::runtime_error("No span can be found with les than 2 values");
    int minSpan = std::abs(vec[1] - vec[0]);

        for (size_t i = 0; i < vec.size(); ++i)
        {
            for (size_t j = i + 1; j < vec.size(); ++j)
            {
                int span = std::abs(vec[j] - vec[i]);
                minSpan = std::min(minSpan, span);
            }
        }
        return minSpan;
}

int Span::longestSpan()
{
    if(vec.size() < 2)
        throw std::runtime_error("No span can be found with les than 2 values");
    int max = *std::max_element(vec.begin(), vec.end());
	int min = *std::min_element(vec.begin(), vec.end());
	return (max - min);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
        size_t currentSize = vec.size();
        size_t elementsToAdd = std::distance(begin, end);

        if (currentSize + elementsToAdd > static_cast<size_t>(max_len))
            throw std::runtime_error("Max length for Span reached");

        for (std::vector<int>::iterator it = begin; it != end; ++it)
        {
            vec.push_back(*it);
        }
}

void Span::show()
{
    int i = 0;
    for(std::vector<int>::iterator it = vec.begin();it != vec.end(); it++)
    {
        if(i % 20 == 0)
            std::cout<<"\n";
        std::cout<<*it<<" ";
        i++;
    }
    std::cout<<std::endl;
}