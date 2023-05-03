#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    try
    {
        int buf[argc - 1];
        int m = 0;
        PmergeMe pmergeme;
        // (void)argc;
        pmergeme.validInput(argc, argv);

        pmergeme.mergeSort(buf, m, (pmergeme.getSize() - 1));
        std::cout << pmergeme.getSize() << std::endl;
        pmergeme.showU();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}