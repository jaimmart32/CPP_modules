#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
private:
    /* atributes */
    std::string _first_name;
    std::string _last_name;
    std::string _nick_name;
    int _phone_number;
    std::string _dark_secret;
public:
    /* methods */
    Contact();
    Contact(std::string, std::string, std::string, int, std::string);
    ~Contact();
};
#endif