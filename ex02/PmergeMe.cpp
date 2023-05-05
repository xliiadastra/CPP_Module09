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
    this->sort.reserve(size);
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
            if (!(ss >> tmp))
                throw IntOverFlowException();
            else
                this->sort.push_back(tmp);
        }
        ++ptr;
    }
    this->sort_buf.reserve(size);
}

void PmergeMe::mergeSortVector(int m, int middle, int n)
{
    int i = m;
    int j = middle + 1;
    int k = m;

    while (i <= middle && j <= n)
    {
        if (this->sort[i] <= this->sort[j])
            this->sort_buf[k++] = this->sort[i++];
        else
            this->sort_buf[k++] = this->sort[j++];
    }

    if (i > middle)
        for (int t = j; t <= n; ++t)
            this->sort_buf[k++] = this->sort[t];
    else
        for (int t = i; t <= middle; ++t)
            this->sort_buf[k++] = this->sort[t];

    for (int t = m; t <= n; ++t)
        this->sort[t] = this->sort_buf[t];
}

void PmergeMe::mergeSort(int m, int n)
{
    if (m < n)
    {
        int middle = (m + n) / 2;
        mergeSort(m, middle);
        mergeSort(middle + 1, n);
        mergeSortVector(m, middle, n);
    }
    
}

void PmergeMe::showU(char ** argv)
{
    std::cout << "Before : ";
    for (int i = 0; i < this->getSize(); ++i)
    {
        if (i == (this->getSize() - 1))
            std::cout << argv[i];
        else
            std::cout << argv[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "After :  ";
    for (std::vector<int>::const_iterator it = this->sort.begin(); it != sort.end(); ++it)
    {
        if (it == (sort.end() - 1))
            std::cout << *it;
        else
            std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << this->sort.size()
              << " elements with std::vector<int> : " << this->time_to_clock.front() << " us" << std::endl;
    // std::cout << "Time to process a range of " << this->sort.size()
    //           << " elements with std::list : " << 0.00031 << " us" << std::endl;
    // std::cout << sort.size() << " " << sort.size() << std::endl;
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

void PmergeMe::setClock(clock_t& start, clock_t& end)
{
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    this->time_to_clock.push_back(time * 1000000.0);
}


const char* PmergeMe::TooManyArgvException::what (void) const throw()
{
    return "Error: Too many argument.\n ex) ./PmergeMe \"3 5 9 7 4\"";
}

const char* PmergeMe::IntOverFlowException::what (void) const throw()
{
    return "Error: The range of positive integers is limited from 0 to 2147483647.";
}


const char* PmergeMe::IsNotIntegerException::what (void) const throw()
{
    return "Error: Only positive integers that need to be sorted are accepted.";
}
