#include <iostream>
#include <sstream>
#include <string>
#include <map>

int main()
{
    // std::string a = "1255.12";
    // std::stringstream ss;
    // float f;

    // ss.str(a);
    // if (!(ss >> f) || !ss.eof())
    //     std::cout << "error" << std::endl;
    std::map<std::string, int> a;
    a["aa"] = 100;
    a["bb"] = 1200;
    a["cc"] = 1300;
    
    std::map<std::string, int>::iterator it = a.begin();
    
    std::map<std::string, int>::iterator it2 = it->first.find("bb");
    std::cout <<  << std::endl;
    return (0);
}