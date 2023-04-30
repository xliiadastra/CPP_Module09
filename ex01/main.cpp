#include "RPN.hpp"

int main(int argc, char *argv[])
{
    try
    {
        Rpn rpn;
        
        rpn.validArgv(argc, argv);
        rpn.goStack();
        rpn.run();
    }
    catch (const std::string msg)
    {
        std::cout << msg << std::endl;
    }
    return 0;
}