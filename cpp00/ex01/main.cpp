#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook   new_phonebook;
    std::string option;

    while(true)
    {
        std::cout << "*******PHONEBOOK MENU*******" << std::endl;
        std::cout << "* Type 'ADD' to add a new contact" << std::endl;
        std::cout << "* Type 'SEARCH' to display a specific contact" << std::endl;
        std::cout << "* Type 'EXIT' to exit the Phonebook" << std::endl;
        std::cout << "MAX NUMBER OF CONTACTS = 8" << std::endl;

        std::cin >> option;

        if(option == "ADD")
        {
            Contact newContact = Contact();
            new_phonebook.add(newContact);
        }
        else if(option == "SEARCH")
        {
            std::cout << "Type the index of the contact to display" << std::endl;

        }
        else if(option == "EXIT")
        {
            new_phonebook.exit();
            return 0;
        }
        else
            std::cout << "Invalid option!" << std::endl;
        
        std::cin.clear();
    }
    return 1;
}