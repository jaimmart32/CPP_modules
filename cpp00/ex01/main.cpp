#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook   new_phonebook;
    std::string option;

    while(true)
    {
        std::cout << "*******PHONEBOOK MENU**************************" << std::endl;
        std::cout << "* Type 'ADD' to add a new contact             *" << std::endl;
        std::cout << "* Type 'SEARCH' to display a specific contact *" << std::endl;
        std::cout << "* Type 'EXIT' to exit the Phonebook           *" << std::endl;
        std::cout << "*** MAX NUMBER OF CONTACTS = 8              ***" << std::endl;
        std::cout << "***********************************************" << std::endl; 

        std::cout << "Enter your desired option: ";
        std::cin >> option;

        if(option == "ADD")
        {
            new_phonebook.add();
        }
        else if(option == "SEARCH")
        {
            
            new_phonebook.search();
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
