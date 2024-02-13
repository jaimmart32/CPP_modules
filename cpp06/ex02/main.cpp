#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base base = Base();
    Base *base_ptr = &base;
    Base *ptr1 = generate();

    Base &ref1 = *ptr1;
    Base &ref3 = base;

    identify(ptr1);
    identify(base_ptr);
    std::cout<<"***********************************"<<std::endl;
    identify(ref1);
    identify(ref3);

    delete ptr1;
}