#include "RPN.hpp"

int main(int argc, char *argv[])
{
    try
    {
        Rpn rpn;
        
        rpn.validArgv(argc, argv);
        rpn.goStack();
    }
    catch (const std::string msg)
    {
        std::cerr << msg << std::endl;
    }
    return 0;
}