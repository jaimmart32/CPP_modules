#include <string>
#include <iostream>

int main()
{
     std::string str = "HI THIS IS BRAIN";
     std::string *stringPTR = &str;
     std::string &stringREF = str;

     std::cout << "address of the string variable: " << &str << std::endl;
     std::cout << "address held by stringPTR: " << stringPTR << std::endl;
     std::cout << "address held by stringREF: " << &stringREF << std::endl;

     std::cout << std::endl << "value of the string variable: " << str << std::endl;
     std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
     std::cout << "value pointed to by stringREF: " << stringREF << std::endl;
}