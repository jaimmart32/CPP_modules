#include "Span.hpp"

int main() {
    Span sp(30000);

    std::vector<int> numbersToAdd;
    for(int i = 0; i < 10; i++)
        numbersToAdd.push_back(i + 1);
    
    std::cout << "numbersToAdd:" << std::endl;
    for (size_t i = 0; i < numbersToAdd.size(); ++i)
        std::cout << numbersToAdd[i] << " ";
    std::cout<<"\n";

    sp.addNumbers(numbersToAdd.begin(), numbersToAdd.end());
    sp.show();
    srand(time(0));
	for (int i = 0; i < 29990; i++)
	{
		int random = rand() % 100;
		sp.addNumber(random);
	}
    //sp.show();

    Span sp2(15);

    srand(time(0));
	for (int i = 0; i < 15; i++)
	{
		int random = rand() % 100;
		sp2.addNumber(random);
	}
    std::cout<<"**************************************************"<<std::endl;
    sp2.show();
    std::cout<<"**************************************************"<<std::endl;
    std::cout<<"Shortest span in sp2: "<<sp2.shortestSpan()<<std::endl;
    std::cout<<"Longest span in sp2: "<<sp2.longestSpan()<<std::endl;

    std::cout<<"**************************************************"<<std::endl;
    try
    {
        sp2.addNumber(42);
    }
    catch(const std::exception& e)
    {
        std::cerr<<"\033[0;31mError : "<<e.what()<<"\033[0m"<<std::endl;
    }
    std::cout<<"**************************************************"<<std::endl;

    Span sp3(5);

    sp3.addNumber(42);
    try
    {
        sp3.longestSpan();
        std::cout<<sp3.longestSpan()<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr<<"\033[0;31mError : "<<e.what()<<"\033[0m"<<std::endl;
    }
    
    return 0;
}