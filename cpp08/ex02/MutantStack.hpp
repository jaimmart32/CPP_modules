#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <list>
#include <iostream>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack(){}
    MutantStack(const MutantStack &source)
    {
        *this = source;
    }
    MutantStack &operator=(const MutantStack &source)
    {
        if(this != &source)
            this->c = source.c;
        return *this;
    }
    ~MutantStack(){}

    /*container_type is a typedef member within std::stack<T> that represents
    the type of the underlying container in stack(deque). We will use aliases
    for that type of container iterators*/

    //normal iterator
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin()
    {
        return this->c.begin();
    }
    iterator end()
    {
        return this->c.end();
    }

    //reverse iterator
    typedef typename std::stack<T>::container_type::reverse_iterator rev_iterator;

    rev_iterator rbegin()
    {
        return this->c.rbegin();
    }
    rev_iterator rend()
    {
        return this->c.rend();
    }

    //const iterator
    typedef typename std::stack<T>::container_type::const_iterator c_iterator;

    c_iterator cbegin() const
    {
        return this->c.cbegin();
    }
    c_iterator cend() const
    {
        return this->c.cend();
    }

    //const_reverse iterator
    typedef typename std::stack<T>::container_type::const_reverse_iterator cr_iterator;

    cr_iterator crbegin() const
    {
        return this->c.crbegin();
    }
    cr_iterator crend() const
    {
        return this->c.crend();
    }
};

#endif