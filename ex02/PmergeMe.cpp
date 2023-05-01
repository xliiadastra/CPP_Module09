#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::validInput(int argc, char*& argv)
{
    if (argc != 2)
        throw TooManyArgvException();
    else
    {
        std::string valid_string = argv;
        size_t pos = valid_string.find_first_not_of("0123456789 ");
        if (pos != std::string::npos)
            throw IsNotIntegerException();
        else
            while ()
                this->sort.push_back(스플릿기준으로 number 넣기);
    }
}

const char* PmergeMe::TooManyArgvException::what (void) const throw()
{
    return "Error: Too many argument.\n ex) ./PmergeMe \"3 5 9 7 4\"";
}

const char* PmergeMe::IsNotIntegerException::what (void) const throw()
{
    return "Error: Only positive integers that need to be sorted are accepted.";
}
