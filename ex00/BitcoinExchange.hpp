#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>

class BitcoinExchange {
private:
	int m_fd;
	BitcoinExchange() {};
	~BitcoinExchange() {};

public:
	BitcoinExchange(int fd) { m_fd = fd; };
};

#endif
