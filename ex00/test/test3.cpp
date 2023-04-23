#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string a = "1255.12";
    std::stringstream ss;
    float f;

    ss.str(a);
    if (!(ss >> f) || !ss.eof())
        std::cout << "error" << std::endl;
    std::cout << f << std::endl;
    return (0);
}