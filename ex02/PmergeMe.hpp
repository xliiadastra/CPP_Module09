#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <algorithm>
# include <exception>

class PmergeMe
{
private:
    std::vector<int>    sort;

    PmergeMe(PmergeMe& orig);
    PmergeMe& operator=(PmergeMe& orig);

public:
    PmergeMe();
    ~PmergeMe();

    void validInput(int argc, char*& argv);
    // std::vector<int> goSplit(std::string str, char dlim);



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