#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>

class BitcoinExchange {
private:
//	int 	m_fd;
//	string	m_file_name;
	std::map<std::string, std::string> database;
//	BitcoinExchange(BitcoinExchange& orig) { if (this != orig) m_file_name = orig->m_file_name; };
	BitcoinExchange&	operator=(const BitcoinExchange& orig) { this->database = orig.database; return (*this); };

public:
	BitcoinExchange();
//	BitcoinExchange(std::string file_name);
	~BitcoinExchange();

	std::map<std::string, std::string> getDatebase() const { return this->database; };
	

	std::map<std::string, std::string>& make_database();
};

#endif
