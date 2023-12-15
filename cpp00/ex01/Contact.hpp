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
    Contact(std::string, std::string, std::string, int, std::string);
    ~Contact();
};

Contact::Contact(std::string first_name, std::string last_name,
 std::string nick_name, int phone_number, std::string dark_secret)
    : _first_name(first_name),
     _last_name(last_name),
     _nick_name(nick_name),
     _phone_number(phone_number),
     _dark_secret(dark_secret)
{

}

Contact::~Contact()
{
}
#endif