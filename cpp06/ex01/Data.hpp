#ifndef DATA_HPP
#define DATA_HPP

class Data
{
private:
    char c;
    int i;
    float f;
    double d;
public:
    Data();
    Data(const Data &source);
    Data &operator=(const Data &source);
    ~Data();
};

#endif