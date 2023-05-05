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
    this->v_sort.reserve(size);
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
            {
                this->v_sort.push_back(tmp);
                this->l_sort.push_back(tmp);
            }
        }
        ++ptr;
    }
    this->v_buf.reserve(size);
}

void PmergeMe::goMergeSortVector(int m, int middle, int n)
{
    int i = m;
    int j = middle + 1;
    int k = m;

    while (i <= middle && j <= n)
    {
        if (this->v_sort[i] <= this->v_sort[j])
            this->v_buf[k++] = this->v_sort[i++];
        else
            this->v_buf[k++] = this->v_sort[j++];
    }

    if (i > middle)
        for (int t = j; t <= n; ++t)
            this->v_buf[k++] = this->v_sort[t];
    else
        for (int t = i; t <= middle; ++t)
            this->v_buf[k++] = this->v_sort[t];

    for (int t = m; t <= n; ++t)
        this->v_sort[t] = this->v_buf[t];
}

void PmergeMe::mergeSortVector(int m, int n)
{
    if (m < n)
    {
        int middle = (m + n) / 2;
        mergeSortVector(m, middle);
        mergeSortVector(middle + 1, n);
        goMergeSortVector(m, middle, n);
    }    
}

void PmergeMe::goMergeSortList(std::list<int>& list, std::list<int>& left_half, std::list<int>& right_half)
{
    std::list<int>::iterator left = left_half.begin();
    std::list<int>::iterator right = right_half.begin();

    while (left != left_half.end() && right != right_half.end())
    {
        if (*left <= *right) {
            list.splice(list.end(), left_half, left++);
        } else {
            list.splice(list.end(), right_half, right++);
        }
    }

    while (left != left_half.end())
        list.splice(list.end(), left_half, left++);

    while (right != right_half.end())
        list.splice(list.end(), right_half, right++);
}

void PmergeMe::mergeSortList(std::list<int>& list)
{
    if (list.size() > 1)
    {
        std::list<int> left_half, right_half;
        std::list<int>::iterator middle = this->getMiddleList(list);
        left_half.splice(left_half.end(), list, list.begin(), middle);
        right_half.splice(right_half.end(), list, middle, list.end());
        mergeSortList(left_half);
        mergeSortList(right_half);

        goMergeSortList(list, left_half, right_half);
    }
}

std::list<int>::iterator PmergeMe::getMiddleList(std::list<int>& list)
{
    std::list<int>::iterator slow = list.begin();
    std::list<int>::iterator fast = list.begin();

    while (fast != list.end() && ++fast != list.end())
    {
        ++fast;
        ++slow;
    }
    return slow;
}

void PmergeMe::readyMergeSortList()
{
    this->mergeSortList(this->l_sort);
}

void PmergeMe::showU(char ** argv)
{
    std::cout << "Before Input : ";
    for (int i = 0; i < this->getSize(); ++i)
    {
        if (i == (this->getSize() - 1))
            std::cout << argv[i];
        else
            std::cout << argv[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "After Vector : ";
    for (std::vector<int>::const_iterator it = this->v_sort.begin(); it != this->v_sort.end(); ++it)
    {
        if (it == (v_sort.end() - 1))
            std::cout << *it;
        else
            std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "After List   : ";
    for (std::list<int>::const_iterator it = this->l_sort.begin(); it != this->l_sort.end(); ++it)
    {
        if (it == (--(this->l_sort.end())))
            std::cout << *it;
        else
            std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << this->v_sort.size()
              << " elements with std::vector<int> : " << this->time_to_clock.front() << " us" << std::endl;
    std::cout << "Time to process a range of " << this->l_sort.size()
              << " elements with std::list<int> : " << this->time_to_clock.back() << " us" << std::endl;
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
