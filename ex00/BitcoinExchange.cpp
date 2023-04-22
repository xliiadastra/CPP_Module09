#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// data.csv file open -> input database
	std::ifstream	ifs;
	std::string		check_header;

	ifs.open("./data.csv");
	if (!ifs.is_open())
		std::cerr << "Error: failed to open file" << std::endl;
	std::getline(ifs, check_header, '\n');
	if (check_header != "date,exchange_rate")
		std::cerr << "Error: The header of the file must be 'data,exchange_rate'." << std::endl;
	while (ifs)
	{	
		for (std:: = 0; )
		std::getline(ifs, database, '\n');
	}
}

//BitcoinExchange::BitcoinExchange(std::string m_file_name)
//{
	// 'file_name.csv' file open -> input database
//}

BitcoinExchange::~BitcoinExchange()
{
	// delete database
}

std::map<std::string, std::string>&	BitcoinExchange::make_database()
{
}
