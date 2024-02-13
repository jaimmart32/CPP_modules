#include "whatever.hpp"

int main()
{
    int num = 42;
    int num2 = 32;
    int maxi, mini = 0;

    std::cout<<"num = "<<num<<std::endl;
    std::cout<<"num2 = "<<num2<<std::endl;
    swap(num, num2);
    std::cout<<"********************************************"<<std::endl;
    std::cout<<"after swap call, num = "<<num<<std::endl;
    std::cout<<"after swap call, num2 = "<<num2<<std::endl;
    maxi = max(num, num2);
    mini = min(num, num2);
    std::cout<<"********************************************"<<std::endl;
    std::cout<<"maxi = "<<maxi<<std::endl;
    std::cout<<"mini = "<<mini<<std::endl;


    std::cout<<"\033[0;34m********************************************"<<std::endl;
    char c = 'a';
    char c2 = 'z';
    char maxc, minc = 0;

    std::cout<<"c = "<<c<<std::endl;
    std::cout<<"c2 = "<<c2<<std::endl;
    swap(c, c2);
    std::cout<<"********************************************"<<std::endl;
    std::cout<<"after swap call, c = "<<c<<std::endl;
    std::cout<<"after swap call, c2 = "<<c2<<std::endl;
    maxc = max(c, c2);
    minc = min(c, c2);
    std::cout<<"********************************************"<<std::endl;
    std::cout<<"maxc = "<<maxc<<std::endl;
    std::cout<<"minc = "<<minc<<std::endl;
    std::cout<<"********************************************\033[0m"<<std::endl;

    std::cout<<"\033[0;33m********************************************"<<std::endl;
    float f = 9.9;
    float f2 = 12.2;
    float maxf, minf = 0.0;
    std::cout<<"f = "<<f<<std::endl;
    std::cout<<"f2 = "<<f2<<std::endl;
    swap(f, f2);
    std::cout<<"********************************************"<<std::endl;
    std::cout<<"after swap call, f = "<<f<<std::endl;
    std::cout<<"after swap call, f2 = "<<f2<<std::endl;
    maxf = max(f, f2);
    minf = min(f, f2);
    std::cout<<"********************************************"<<std::endl;
    std::cout<<"maxf = "<<maxf<<std::endl;
    std::cout<<"minf = "<<minf<<std::endl;
    std::cout<<"********************************************\033[0m"<<std::endl;
}