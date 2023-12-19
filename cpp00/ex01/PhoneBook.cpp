#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
    : _num_of_contacts(0)
{
}

PhoneBook::~PhoneBook()
{
}

void    PhoneBook::add(Contact newContact)
{
    if (_num_of_contacts < 8)
        _contacts[_num_of_contacts++] = newContact;
//    else
        //se borra el 0 se corren a la izq y se añade newContact
        // al index 8
}

void    PhoneBook::search(int index)
{
    if (index >= 0 && index < _num_of_contacts)
        std::cout << "Muestra info del contacto" << std::endl;
}

void    PhoneBook::exit(void)
{
    std::cout << "Exiting PhoneBook..." << std::endl;
}