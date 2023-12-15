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
    PhoneBook(Contact, int);
    ~PhoneBook();
};

PhoneBook::PhoneBook(Contact contact, int num_of_contacts)
{
}

PhoneBook::~PhoneBook()
{
}

#endif