#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    try
    {
        PmergeMe pmergeme;

        pmergeme.validInput(argc, argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}