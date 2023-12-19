#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    /* atributes */
    Contact _contacts[8];
    int _num_of_contacts;
public:
    PhoneBook(void);
    ~PhoneBook();

    void    add(void);
    void    search(void);
    void    exit(void);
};
#endif