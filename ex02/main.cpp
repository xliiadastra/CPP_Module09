#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    try
    {
        PmergeMe pmergeme;
        // (void)argc;
        pmergeme.validInput(argc, argv);

        pmergeme.showU();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}