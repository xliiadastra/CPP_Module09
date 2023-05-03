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
        size_t pos = this->ft_trim(valid_string).find_first_not_of("0123456789");
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

    this->size = argc - 1;
    // for (std::size_t i = 0; i < this->sort.size(); ++i)
    //     std::cout << this->sort[i] << " " << i << std::endl;
    // std::cout << this->sort_bf.size() << std::endl;
}

void PmergeMe::mergeSortVector(int* buf, int m, int middle, int n)
{
    int i = m;
    int j = middle + 1;
    int k = m;

    while (i <= middle && j <= n)
    {
        if (this->sort_bf[i] <= this->sort_bf[j])
        {
            buf[k] = this->sort_bf[i];
            i++;
        }
        else
        {
            buf[k] = this->sort_bf[j];
            j++;
        }
        k++;
    }

    if (i > middle)
    {
        for (int t = j; t <= n; ++t)
        {
            buf[k] = this->sort_bf[t];
            k++;
        }
    }
    else
    {
        for (int t = i; t <= middle; ++t)
        {
            buf[k] = this->sort_bf[t];
            k++;
        }
    }

    for (int t = m; t <= n; ++t)
        this->sort_af.push_back(buf[t]);
}

void PmergeMe::mergeSort(int* buf, int m, int n)
{
//    int n = this->getSize();

    if (m < n)
    {
        int middle = (m + n) / 2;
        mergeSort(buf, m, middle);
        mergeSort(buf, middle + 1, n);
        mergeSortVector(buf, m, middle, n);
    }
}

void PmergeMe::showU()
{
    std::cout << "Before : ";
    for (std::vector<int>::const_iterator it = this->sort_bf.begin(); it != sort_bf.end(); ++it)
    {
        if (it == (sort_bf.end() - 1))
            std::cout << *it;
        else
            std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "After :  ";
    for (std::vector<int>::const_iterator it = this->sort_af.begin(); it != sort_af.end(); ++it)
    {
        if (it == (sort_af.end() - 1))
            std::cout << *it;
        else
            std::cout << *it << " ";
    }
    std::cout << std::endl;

    // std::cout << "Time to process a range of " << this->sort_bf.size()
    //           << " elements with std::vector<int> : " << 0.00031 << " us" << std::endl;
    // std::cout << "Time to process a range of " << this->sort_af.size()
    //           << " elements with std::list : " << 0.00031 << " us" << std::endl;
    std::cout << sort_af.size() << " " << sort_bf.size() << std::endl;
}

std::string PmergeMe::ft_trim(std::string str)
{
    std::string valid_string = " ";

    // if (str == "")
    //     throw
    str.erase(0, str.find_first_not_of(valid_string));
    while (std::isspace(str.back()))
        str.erase(str.find_last_not_of(valid_string) + 1, str.length() - 1);

    return str;
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
