#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// data.csv file open -> input database

	this->ifs.open("./data.csv");
	if (!this->ifs.is_open()) 
		throw std::string("Error: failed to open file");
}

//BitcoinExchange::BitcoinExchange(std::string m_file_name)
//{
	// 'file_name.csv' file open -> input database
//}

BitcoinExchange::~BitcoinExchange()
{
	if (this->ifs)
		this->ifs.close();
}

void	BitcoinExchange::makeDatabase()
{
	std::string	check_header;
	std::string	buf;

	std::getline(this->ifs, check_header);
	if (check_header != "date,exchange_rate")
		throw std::string("Error: The header of the file must be 'data,exchange_rate'.");
	while (std::getline(ifs, buf))
	{
		// std::istringstream	ss;
		// std::string key, value;
		// getline(ss, key, ',');
		// getline(ss, value, ',');
		this->split(buf);
		this->validateData();
		// std::istringstream	data_stream(buf);
		// // data_stream.str(buf);
		// std::getline(data_stream, database, '\n');
	}
}

std::tm BitcoinExchange::getDate(const std::string& date_str)
{
    std::tm date_tm = {};
    std::istringstream validate(date_str);
    
	validate >> std::get_time(&date_tm, "%Y-%m-%d");
	if (validate.fail())
		throw std::string("Error: Not a valid date.");

	return date_tm;
}

void	BitcoinExchange::validateData()
{
	std::istringstream	validate;
	std::map<std::string, double>::iterator it;
	// std::tm	data_tm = {};

	it = this->database.end();
	std::tm date_tm1 = this->getDate((--it)->first);
	if (this->database.size() == 1)
		return ;
	std::tm date_tm2 = this->getDate((--it)->first);
	if (std::difftime(std::mktime(&date_tm1), std::mktime(&date_tm2)) < 0)
		throw std::string("Error: data.csv: Dates are not sorted." + it->first + " " + (++it)->first);
	

}

double	BitcoinExchange::is_float(const std::string& value)
{
	char*	endptr;
	double	result = 0.00;

	result = std::strtod(value.c_str(), &endptr);
	std::cout << value << " " << result << std::endl;
	if (!(endptr != value.c_str() && *endptr == '\0'))
		throw std::string("Error: data.csv: Is not float");
	return result;
}

void	BitcoinExchange::split(const std::string& buf)
{
	std::stringstream	ss;
	std::string key, value;

	ss.str(buf);
	std::getline(ss, key, ',');
	std::getline(ss, value, ',');
	if (std::getline(ss, key, ','))
		throw std::string("Error: Too many columns");
	else
		this->database[key] = this->is_float(value);
}

void	BitcoinExchange::run()
{
	// for (std::map<std::string, double>::iterator it = this->database.begin();
	// 	it != this->database.end(); ++it) {
	// 		std::cout << "1. " << it->first << " 2. " << it->second << std::endl;
	// 	}
}

void	BitcoinExchange::errorExit()
{
	throw std::string("Error!");
	this->ifs.close();
}