#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <algorithm>
# include <map>
# include <exception>
# include <sstream>
# include <ctime>
# include <iomanip>

class BitcoinExchange {
private:
	std::ifstream	ifs;
	std::map<std::string, float> database;
//	std::map<std::string, float> input_database;
//	BitcoinExchange(BitcoinExchange& orig) { if (this != orig) m_file_name = orig->m_file_name; };
//	BitcoinExchange&	operator=(const BitcoinExchange& orig) { this->database = orig.database; return (*this); };

public:
	BitcoinExchange();
//	BitcoinExchange(std::string file_name);
	~BitcoinExchange();

	std::map<std::string, float> getDatebase() const { return this->database; };

	void	makeDatabase();
	void	goSplit(const std::string& buf);
	bool	isValidDate(const std::string& key);
	float	isValidFloat(const std::string& value);

	void	makeInputDatabase(char* input);
	void	goInputSplit(std::string& buf);
//	bool	isInputValidDate(const std::string& dateString);
	float	isInputValidFloat(const std::string& value);
	std::string	lowerDate(const std::string& input_key);

	void	run(const std::string& input_key, const float& input_value);
	void	test();
//	void	run(const std::string& input_key, const std::string& input_value);
};

#endif
