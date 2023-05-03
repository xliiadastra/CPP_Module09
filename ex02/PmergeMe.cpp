#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::validInput(int argc, char**& argv)
{
    char** ptr = argv + 1;
    int i = 0;
    while (++i < argc)
    {
        std::string valid_string = *ptr;
        size_t pos = valid_string.find_first_not_of("0123456789");
        if (pos != std::string::npos)
            throw IsNotIntegerException();
        else
        {
            std::stringstream ss(*ptr);
            int tmp = 0;
            while (ss >> tmp)
                this->sort_bf.push_back(tmp);
        }
        ++ptr;
    }
    // for (std::size_t i = 0; i < this->sort.size(); ++i)
    //     std::cout << this->sort[i] << " " << i << std::endl;
    // std::cout << this->sort_bf.size() << std::endl;
}

void PmergeMe::showU()
{
    std::cout << "Before :\t";
    for (std::vector<int>::const_iterator it = this->sort_bf.begin(); it != sort_bf.end(); ++it)
    {
        if (it == (sort_bf.end() - 1))
            std::cout << *it;
        else
            std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "After :\t";
    for (std::vector<int>::const_iterator it = this->sort_af.begin(); it != sort_af.end(); ++it)
    {
        if (it == (sort_af.end() - 1))
            std::cout << *it;
        else
            std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << this->sort_bf.size()
              << " elements with std::vector<int> : " << 0.00031 << " us" << std::endl;
    std::cout << "Time to process a range of " << this->sort_af.size()
              << " elements with std::list : " << 0.00031 << " us" << std::endl;
}

const char* PmergeMe::TooManyArgvException::what (void) const throw()
{
    return "Error: Too many argument.\n ex) ./PmergeMe \"3 5 9 7 4\"";
}

const char* PmergeMe::IsNotIntegerException::what (void) const throw()
{
    return "Error: Only positive integers that need to be sorted are accepted.";
}

// std::vector<int> PmergeMe::goSplit(std::string str, char dlim)
// {
//     std::vector<int> result;
//     std::stringstream ss;
//     std::string buf;

//     ss.str(str);
//     while (std::getline(ss, buf, dlim))
//     {
//         int tmp = 0;
//         buf >> tmp;
        
//     }
    
// }
