#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    try
    {
        PmergeMe pmergeme;

        pmergeme.setSize(argc - 1);
        pmergeme.validInput(argc, argv);

        clock_t start = clock();
        pmergeme.mergeSort(0, pmergeme.getSize() - 1);
        clock_t end = clock();

        pmergeme.setClock(start, end);
        pmergeme.showU(argv + 1);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}