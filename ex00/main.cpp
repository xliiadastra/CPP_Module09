#include "BitcoinExchange.hpp"

int	main(int argc, char* argv[])
{
	if (argc == 2)
	{
		std::ifstream ifs(argv[1]); // ios::app, ios::binary
		if (!argv[1])
		{
			std::cerr << "Cannot open file " << std::endl;
			exit(1);
		}
		while (ifs)
		{
			std::string	str;
			getline(ifs, str);

			std::cout << str << std::endl;
		}
	}
	else
		std::cout << "Bad Argument: just one input '.csv' file name" << std::endl;

	return (0);
}
