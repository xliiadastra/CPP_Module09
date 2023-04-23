#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

int main() {
    double x = 3.14;
	std::string a("2.14");
	char * enptr;
	double b = std::strtod(a.c_str(), &enptr);

	std::cout << b << std::endl;
	std::cout << std::fixed << std::setprecision(2) << x << std::endl;
	std::cout << x << std::endl;
	std::cout << std::fixed << std::setprecision(2) << b  << std::endl;
	return 0;
}
