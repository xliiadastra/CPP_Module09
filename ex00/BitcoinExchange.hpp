#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <map>
# include <exception>
# include <sstream>
# include <ctime>

class BitcoinExchange {
private:
//	int 	m_fd;
//	string	m_file_name;
	std::ifstream	ifs;
	std::map<std::string, double> database;
//	BitcoinExchange(BitcoinExchange& orig) { if (this != orig) m_file_name = orig->m_file_name; };
//	BitcoinExchange&	operator=(const BitcoinExchange& orig) { this->database = orig.database; return (*this); };

public:
	BitcoinExchange();
//	BitcoinExchange(std::string file_name);
	~BitcoinExchange();

	std::map<std::string, double> getDatebase() const { return this->database; };
	

	void	makeDatabase();
	void	errorExit();
	void	split(const std::string& buf);
	double	is_float(const std::string& value);
	void	validateData();
	std::tm getDate(const std::string& date_str);

	void	run();
};

#endif
