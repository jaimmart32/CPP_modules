#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string first_name, std::string last_name,
 std::string nick_name, std::string phone_number, std::string dark_secret)
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

std::string Contact::get_f_name()
{
    return this->_first_name;
}

std::string Contact::get_l_name()
{
    return this->_last_name;
}

std::string Contact::get_n_name()
{
    return this->_nick_name;
}

std::string Contact::get_p_number()
{
    return this->_phone_number;
}

std::string Contact::get_d_secret()
{
    return this->_dark_secret;
}