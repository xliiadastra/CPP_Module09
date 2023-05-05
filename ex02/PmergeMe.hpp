#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <ctime>

# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <iterator>
# include <algorithm>
# include <exception>

class PmergeMe
{
private:
    int size;

    std::vector<int>    sort;
    std::vector<int>    sort_buf;

    std::vector<double> time_to_clock;

    PmergeMe(PmergeMe& orig);
    PmergeMe& operator=(PmergeMe& orig);

public:
    PmergeMe();
    ~PmergeMe();

    void validInput(int argc, char**& argv);

    void mergeSortVector(int m, int middle, int n);
    void mergeSort(int m, int n);

    std::string ft_trim(std::string str);

    void showU(char** argv);

    void setClock(clock_t& start, clock_t& end);
    const std::vector<double>& getClock() const { return this->time_to_clock; };

    void setSize(int size) { this->size = size; };
    const int& getSize() const {return this->size;};

    class TooManyArgvException : public std::exception
    {
        virtual const char * what(void) const throw();
    };

    class IntOverFlowException : public std::exception
    {
        virtual const char * what(void) const throw();
    };

    class IsNotIntegerException : public std::exception
    {
        virtual const char * what(void) const throw();
    };
};

#endif