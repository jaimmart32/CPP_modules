#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream> // std::cout, std::endl
#include <string> // .length(), .substr()
#include <iomanip> // std::setw()
#include <algorithm> // std::all_of()
#include <limits> // std::numeric_limits

class Contact
{
private:
    /* atributes */
    std::string _first_name;
    std::string _last_name;
    std::string _nick_name;
    std::string _phone_number;
    std::string _dark_secret;
public:
    /* methods */
    Contact();
    Contact(std::string, std::string, std::string, std::string, std::string);
    ~Contact();

    std::string get_f_name();
    std::string get_l_name();
    std::string get_n_name();
    std::string get_p_number();
    std::string get_d_secret();
};
#endif