#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Form
{
private:
    const std::string name;
    bool    is_signed;
    const int sign_grade;
    const int exec_grade;
public:
    Form();
    Form(const Form &source);
    Form &operator=(const Form &source);
    ~Form();

    void    beSigned();
};

#endif