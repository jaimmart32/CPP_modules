#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
    : _num_of_contacts(0)
{
}

PhoneBook::~PhoneBook()
{
}

void    print_atribute(std::string atribute)
{
    int length = atribute.length();

    if (length > 10)
        std::cout << atribute.substr(0,9) << ".";
    else
        std::cout << std::setw(10) << atribute;
}

void    display_contacts(Contact contacts[8], int num_contacts)
{
    std::cout << "*********************************************" << std::endl;
    for (int index = 0; index < num_contacts; index++)
    {
        std::cout << "|";
        print_atribute(std::to_string(index + 1));
        std::cout << "|";
        print_atribute(contacts[index].get_f_name());
        std::cout << "|";
        print_atribute(contacts[index].get_l_name());
        std::cout << "|";
        print_atribute(contacts[index].get_n_name());
        std::cout << "|" << std::endl;
    }
    std::cout << "*********************************************" << std::endl;
}   

void    PhoneBook::add()
{
    std::string f_name;
    std::string l_name;
    std::string n_name;
    std::string phone_num;
    std::string d_secret;

    std::cout << "Enter first name: ";
    std::cin >> f_name;
    std::cin.clear();
    std::cout << "Enter last name: ";
    std::cin >> l_name;
    std::cin.clear();
    std::cout << "Enter nick name: ";
    std::cin >> n_name;
    std::cin.clear();
    std::cout << "Enter phone number: ";
    std::cin >> phone_num;
    std::cin.clear();
    std::cout << "Enter the darkest secret: ";
    std::cin >> d_secret;
    std::cin.clear();

    Contact newContact = Contact(f_name, l_name, n_name, phone_num, d_secret);
    if (_num_of_contacts < 8)
        _contacts[_num_of_contacts++] = newContact;
    else
    {
        _contacts[_num_of_contacts % 8] = newContact;
        _num_of_contacts++;
    }
}

void    PhoneBook::search()
{
    int display_size;
    if (this->_num_of_contacts > 8)
        display_size = 8;
    else
        display_size = this->_num_of_contacts;
    display_contacts(this->_contacts, display_size);

    int index;
    std::cout << "Type the index of the contact to display: ";
    std::cin >> index;
    if (index && index > 0 && index <= 8)
    {
        std::cout << "First Name: " << this->_contacts[index - 1].get_f_name() << std::endl;
        std::cout << "Last Name: " << this->_contacts[index - 1].get_l_name() << std::endl;
        std::cout << "Nick: " << this->_contacts[index - 1].get_n_name() << std::endl;
        std::cout << "Phone Number: " << this->_contacts[index - 1].get_p_number() << std::endl;
        std::cout << "Darkest secret: " << this->_contacts[index - 1].get_d_secret() << std::endl;
    }
    else
        std::cout << "Invalid index, must be between [1 - 8]" << std::endl;
}

void    PhoneBook::exit(void)
{
    std::cout << "Exiting PhoneBook..." << std::endl;
}