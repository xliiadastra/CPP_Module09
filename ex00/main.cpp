#include "BitcoinExchange.hpp"

int	main(int argc, char* argv[])
{
	// if (argc == 2)
	// {
	// 	if (static_cast<std::string>(argv[1]) != "input.txt")
	// 	{
	// 		std::cerr << "Cannot open file " << std::endl;
	// 		exit(1);
	// 	}
	// 	std::ifstream ifs; // ios::app, ios::binary
	// 	ifs.open("./data.csv");
	// 	while (ifs)
	// 	{
	// 		std::string	str;
	// 		getline(ifs, str);

	// 		std::cout << str << std::endl;
	// 	}
	// 	ifs.close();
	// }
	// else
	// 	std::cout << "Bad Argument: just one input 'input.txt' file name" << std::endl;
	// return (0);
	try
	{
		if (argc != 2 || static_cast<std::string>(argv[1]) != "input.txt")
			throw std::string("Bad Argument: just one input 'input.txt' file name");
		
		BitcoinExchange btc;

		btc.makeDatabase();
		btc.showU(argv[1]);
//		btc.run();
//		btc.test();
	}
	catch (std::string& msg)
	{
		std::cerr << msg << std::endl;
	}
	return (0);
}
