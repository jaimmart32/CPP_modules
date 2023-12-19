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

    void    add(Contact);
    void    search(int);
    void    exit(void);
};
#endif