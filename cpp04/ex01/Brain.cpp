#include "Brain.hpp"

Brain::Brain()
{
    std::cout<<"\033[2;30mDefault constructor called: Brain\033[0m"<<std::endl;
    for(int i=0; i < 100; i++)
        this->ideas[i] = "dogmatic idea";
}

Brain::Brain(const Brain &source)
{
    std::cout<<"\033[2;30mCopy constructor called: Brain\033[0m"<<std::endl;
    for(int i=0; i < 100; i++)
        this->ideas[i] = source.ideas[i];
}

Brain   &Brain::operator=(const Brain &source)
{
    if(this != &source)
    {
        for(int i=0; i < 100; i++)
            this->ideas[i] = source.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout<<"\033[2;30mDestructor called: Brain\033[0m"<<std::endl;
}