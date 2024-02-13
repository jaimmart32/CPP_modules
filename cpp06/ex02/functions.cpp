#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    srand(time(0));// to generate diferent random numbers per execution.
    int code = rand() % 3;

    switch(code)
    {
        case 0:
            return new A();
            break;
        case 1:
            return new B();
            break;
        case 2:
            return new C();
            break;
    }
    return 0;
}

void identify(Base* p)
{
    if(A* a_ptr = dynamic_cast<A*>(p))
        std::cout<<"the actual type of the object pointed to by p is: A"<<std::endl;
    else if(B* b_ptr = dynamic_cast<B*>(p))
        std::cout<<"the actual type of the object pointed to by p is: B"<<std::endl;
    else if(C* c_ptr = dynamic_cast<C*>(p))
        std::cout<<"the actual type of the object pointed to by p is: C"<<std::endl;
    else
        std::cerr<<"\033[0;31mp isn't A,B,C type\033[0m"<<std::endl;
}

void identify(Base& p)
{
    try
    {
        A& A_ref = dynamic_cast<A&>(p);//it will throw exception if it cant convert
        (void)A_ref;
        std::cout<<"the actual type of the object pointed to by p is: A"<<std::endl;
        return;
    }
    catch(const std::bad_cast& e){}
    try
    {
        B& B_ref = dynamic_cast<B&>(p);
        (void)B_ref;
        std::cout<<"the actual type of the object pointed to by p is: B"<<std::endl;
        return;
    }
    catch(const std::bad_cast& e){}
    try
    {
        C& C_ref = dynamic_cast<C&>(p);
        (void)C_ref;
        std::cout<<"the actual type of the object pointed to by p is: C"<<std::endl;
        return;
    }
    catch(const std::bad_cast& e){}
    std::cerr<<"\033[0;31mp isn't A,B,C type\033[0m"<<std::endl;
}