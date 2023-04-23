#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// data.csv file open -> input database

	this->ifs.open("./data.csv");
	if (!this->ifs.is_open()) 
		throw std::string("Error: data.csv: Failed to open file or does not exist in this directory.");
}

//BitcoinExchange::BitcoinExchange(std::string m_file_name)
//{
	// 'file_name.csv' file open -> input database
//}

BitcoinExchange::~BitcoinExchange()
{
	if (this->ifs.is_open())
		this->ifs.close();
}

void	BitcoinExchange::makeDatabase()
{
	std::string	check_header;
	std::string	buf;

	std::getline(this->ifs, check_header);
	if (check_header != "date,exchange_rate")
		throw std::string("Error: data.csv: The header of the file must be 'data,exchange_rate'." + check_header);
	while (std::getline(ifs, buf))
		this->goSplit(buf);
}

bool BitcoinExchange::isValidDate(const std::string& key)
{
    struct tm tm;
    char format[11] = "%Y-%m-%d";
    char* result = strptime(key.c_str(), format, &tm);
    return (result != nullptr && *result == '\0');
}

float	BitcoinExchange::isValidFloat(const std::string& value)
{
	std::stringstream	iss;
	float	result;

	iss.str(value);
	if (!(iss >> result) || !iss.eof())
		throw std::string("Error: Is not float :" + value);

	return result;
}

void	BitcoinExchange::goSplit(const std::string& buf)
{
	std::stringstream	ss;
	std::string key, value;

	ss.str(buf);
	std::getline(ss, key, ',');
	if (!isValidDate(key))
 		throw std::string("Error: Is not Date :" + key);

	std::getline(ss, value, ',');
	if (std::getline(ss, key, ','))
		throw std::string("Error: Too many columns :" + key);
	else
		this->database[key] = this->isValidFloat(value);
}

void	BitcoinExchange::makeInputDatabase(char* input)
{
	std::string	check_header;
	std::string	buf;

	if (this->ifs.is_open())
		this->ifs.close();

	std::string	search = input;
	this->ifs.open("./" + search);
	if (!this->ifs.is_open())
		throw std::string("Error: input.txt: Failed to open file or does not exist in this directory.");

	std::getline(this->ifs, check_header);
//	std::cout << "./" + search << check_header << std::endl;
	if (check_header != "date | value")
		throw std::string("Error: input.txt: The header of the file must be 'date | value'." + check_header);
	while (std::getline(ifs, buf))
		this->goInputSplit(buf);
}

void	BitcoinExchange::goInputSplit(std::string& buf)
{
	// std::stringstream	ss;
	// std::string line;

	size_t	pos = buf.find(" | ");
	if (pos == std::string::npos)
	{
		std::cout << "Error: bad input => " + buf << std::endl;
		return ;
	}

	std::string	key = buf.substr(0, pos);
	if (!isInputValidDate(key))
	{
		std::cout << "Error: bad date data." << std::endl;
		return ;
	}
	std::string	value = buf.substr(pos + 3);
	

	// this->database[key] = this->isInputValidFloat(value);
}

bool BitcoinExchange::isInputValidDate(const std::string& key)
{
    struct tm tm;
    char format[11] = "%Y-%m-%d";
    char* result = strptime(key.c_str(), format, &tm);
    return (result != nullptr && *result == '\0');
}

float	BitcoinExchange::isInputValidFloat(const std::string& value)
{
	std::stringstream	iss;
	float	result;

	iss.str(value);
	if (!(iss >> result) || !iss.eof())
		std::string("Error: Is not float :" + value);
	else if (result < 0.0f)
		std::cout << "Error: not a positive number." << std::endl;
	else if (result > 1000.0f)
		std::cout << "Error: too large a number." << std::endl;
	else


	return result;
}


void	BitcoinExchange::run()
{
	


	for (std::map<std::string, float>::iterator it = this->input_database.begin();
		it != this->input_database.end(); ++it) {
			std::cout << "1. " << it->first << " 2. " << it->second
			<< std::endl;
		}
}
