#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <ctime>

# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <list>
# include <iterator>
# include <algorithm>
# include <exception>

class PmergeMe
{
private:
    int size;
    int insertion;

    std::vector<int>    v_sort;
    std::vector<int>    v_buf;

    std::list<int>      l_sort;

    std::vector<double> time_to_clock;

    PmergeMe(const PmergeMe& orig) {*this = orig;};
    PmergeMe& operator=(const PmergeMe& orig) { if (this != &orig) this->size = orig.size; return *this; };

public:
    PmergeMe() : insertion(1000) {};
    ~PmergeMe() {};

    void validInput(int argc, char**& argv);

    void goMergeSortVector(int m, int middle, int n);
    void insertionSort(int m, int n);
    void mergeSortVector(int m, int n);

    void goMergeSortList(std::list<int>& list, std::list<int>& left_half, std::list<int>& right_half);
    void insertionSortList(std::list<int>& list);
    void mergeSortList(std::list<int>& list);
    std::list<int>::iterator getMiddleList(std::list<int>& list);
    void readyMergeSortList();

    std::string ft_trim(std::string str);

    void showU(char** argv);

    void setClock(clock_t& start, clock_t& end);
    const std::vector<double>& getClock() const { return this->time_to_clock; };

    void setSize(int size) { this->size = size; };
    const int& getSize() const {return this->size;};

    class InputArgvException : public std::exception
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