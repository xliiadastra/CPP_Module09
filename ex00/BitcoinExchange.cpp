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
	float	result = 0.0f;

	iss.str(value);
	if (!(iss >> result) || !iss.eof())
		throw std::string("Error: Is not float :" + value + ".");

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
	if (check_header != "date | value")
		throw std::string("Error: input.txt: The header of the file must be 'date | value'." + check_header);
	while (std::getline(ifs, buf))
		this->goInputSplit(buf);
}

void	BitcoinExchange::goInputSplit(std::string& buf)
{
	try
	{
		size_t	pos = buf.find(" | ");
		if (pos == std::string::npos)
			throw std::string("Error: bad input => " + buf);

		const std::string	input_key = buf.substr(0, pos);
		if (!this->isValidDate(input_key))
			throw std::string("Error: bad date data.");

		const std::string	value = buf.substr(pos + 3);		
		float input_value = this->isInputValidFloat(value);
		this->run(input_key, input_value);
	}
	catch (std::string& msg)
	{
		std::cerr << msg << std::endl;
	}
}

float	BitcoinExchange::isInputValidFloat(const std::string& value)
{
	std::stringstream	iss;
	float	result;

	iss.str(value);
	if (!(iss >> result) || !iss.eof())
		throw std::string("Error: Is not float : " + value + ".");
	else if (result < 0.000000f)
		throw std::string("Error: not a positive number.");
	else if (result > 1000.000000f)
		throw std::string("Error: too large a number.");

	return result;
}

void	BitcoinExchange::run(const std::string& input_key, const float& input_value)
{
	std::map<std::string, float>::iterator it = this->database.find(input_key);
	
	if (it != this->database.end())
		std::cout << input_key << " => " << input_value << " = " << this->database[input_key] * input_value << std::endl;
	else
		std::cout << input_key << " => " << input_value << " = " << this->database[lowerDate(input_key)] * input_value << std::endl;
}

std::string BitcoinExchange::lowerDate(const std::string& input_key)
{
	std::map<std::string, float>::iterator it = this->database.lower_bound(input_key);

	--it;
	return it->first;
}

void	BitcoinExchange::test()
{
	for (std::map<std::string, float>::iterator it = this->database.begin();
		it != this->database.end(); ++it) {
			std::cout << it->first << "," << it->second
			<< std::endl;
		}
}
