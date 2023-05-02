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
        {
            std::stringstream ss(argv);
            int tmp = 0;
            while (ss >> tmp)
                this->sort.push_back(tmp);
            // for (std::size_t i = 0; i < this->sort.size(); ++i)
            //     std::cout << this->sort[i] << std::endl;
        }
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
