#include "Contact.hpp"

Contact::Contact()
{
}

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