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

	BitcoinExchange(const BitcoinExchange& orig) { *this = orig; };
	BitcoinExchange&	operator=(const BitcoinExchange& orig) { if (this != &orig) this->database = orig.database; return (*this); };

public:
	BitcoinExchange();
	~BitcoinExchange();

	std::map<std::string, float> getDatebase() const { return this->database; };

	void	makeDatabase();
	void	goSplit(const std::string& buf);
	bool	isValidDate(const std::string& key);
	float	isValidFloat(const std::string& value);

	void	showU(char* input);
	void	goInputSplit(std::string& buf);
//	bool	isInputValidDate(const std::string& dateString);
	float	isInputValidFloat(const std::string& value);
	std::string	lowerDate(const std::string& input_key);

	void	run(const std::string& input_key, const float& input_value);
	void	test();
//	void	run(const std::string& input_key, const std::string& input_value);
};

#endif
