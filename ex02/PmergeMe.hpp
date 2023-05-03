#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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

    std::vector<int>    sort_bf;
    std::vector<int>    sort_af;

    PmergeMe(PmergeMe& orig);
    PmergeMe& operator=(PmergeMe& orig);

public:
    PmergeMe();
    ~PmergeMe();

    void validInput(int argc, char**& argv);
    // std::vector<int> goSplit(std::string str, char dlim);

    void mergeSortVector(int* buf, int m, int middle, int n);
    void mergeSort(int* buf, int m, int n);

    std::string ft_trim(std::string str);

    void showU();

    int& getSize() {return this->size;};

    class TooManyArgvException : public std::exception
    {
        virtual const char * what(void) const throw();
    };

    class IsNotIntegerException : public std::exception
    {
        virtual const char * what(void) const throw();
    };
};

#endif