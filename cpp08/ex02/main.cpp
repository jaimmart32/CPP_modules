#include "MutantStack.hpp"

int main()
{
    std::cout<<"************Mutant************************"<<std::endl;

    MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

    std::cout<<"************list************************"<<std::endl;

    std::list<int> my_list;
	my_list.push_back(5);
	my_list.push_back(17);
	std::cout << my_list.back() << std::endl;
	my_list.pop_back();
	std::cout << my_list.size() << std::endl;
	my_list.push_back(3);
	my_list.push_back(5);
	my_list.push_back(737);
	//[...]
	my_list.push_back(0);
	std::list<int>::iterator it2 = my_list.begin();
	std::list<int>::iterator ite2 = my_list.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::list<int> l(my_list);

    std::cout<<"***********other_iterators*************************"<<std::endl;

	MutantStack<int>::rev_iterator rit = mstack.rbegin();
	MutantStack<int>::rev_iterator rite = mstack.rend();
	++rit;
	--rit;
	while(rit != rite)
	{
		std::cout<<*rit<<std::endl;
		++rit;
	}
}