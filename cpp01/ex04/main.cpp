#include <string>
#include <iostream>
#include <fstream>

std::string sustitute(std::string file_str, std::string s1, std::string s2)
{
    std::string rep_str = "";
    size_t pos = file_str.find(s1);

    while(pos != std::string::npos)
    {
        rep_str += file_str.substr(0, pos);
        rep_str += s2;
        file_str = file_str.substr(pos + s1.length(), file_str.length());
        pos = file_str.find(s1);
    }
    rep_str += file_str;
    return rep_str;
}

int main(int argc, char **argv)
{
    std::string filename;
    std::string replacefile;
    std::string file_str = "";

    if(argc != 4)
    {
        std::cout << "Error, program needs 3 arguments(file, string1, string2) to replace strings." << std::endl;
        return 1;
    }
    filename = argv[1];
    std::ifstream readfile(filename);
    if(!readfile.is_open())
    {
        std::cout << "Error opening: " << filename << std::endl;
        return 1;
    }
    while(readfile)
        file_str += readfile.get();
    file_str = file_str.substr(0, file_str.size() - 1);
    replacefile = filename + ".replace";
    std::ofstream wrightfile(replacefile);
    if(!wrightfile.is_open())
    {
        std::cout << "Error opening: " << replacefile << std::endl;
        return 1;
    }
    wrightfile << sustitute(file_str, argv[2], argv[3]);
    readfile.close();
    wrightfile.close();
    return 0;
}