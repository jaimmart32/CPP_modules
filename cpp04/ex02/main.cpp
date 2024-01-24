#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    //Animal abstract;
    std::cout<<"****************************************************"<<std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    std::cout<<"****************************************************"<<std::endl;
    Dog basic; {
        Dog tmp = basic;
    };

    std::cout<<"****************************************************"<<std::endl;



    Animal *vector[10];

    for(int i=0; i < 10; i++)
    {
        if(i < 5)
            vector[i] = new Dog();
        else
            vector[i] = new Cat();
    }

    for(int i=0; i < 10; i++)
        delete vector[i];
    
    std::cout<<"****************************************************"<<std::endl;

    Animal *extraCat = new Cat();
    extraCat->makeSound();
    Cat realCat;
    Cat copyCat = Cat(realCat);
    std::cout<<"copyCat is a "<<copyCat.getType()<<std::endl;
    delete extraCat;

    std::cout<<"****************************************************"<<std::endl;
    return 0;
}