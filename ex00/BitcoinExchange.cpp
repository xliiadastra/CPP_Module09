#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// data.csv file open -> input database
	database();
}

//BitcoinExchange::BitcoinExchange(std::string m_file_name)
//{
	// 'file_name.csv' file open -> input database
//}

BitcoinExchange::~BitcoinExchange()
{
	// delete database
}

map<int, char>&	BitcoinExchange::make_database()
{
}
