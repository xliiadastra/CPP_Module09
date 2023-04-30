#include "RPN.hpp"

Rpn::Rpn() : input("") {}

Rpn::Rpn(Rpn& orig)
{
}

Rpn& Rpn::operator=(const Rpn& orig)
{
}

Rpn::~Rpn()
{
}

void Rpn::validArgv(const int argc, const char* argv[])
{
    if (argc != 2)
        throw std::string("Error: Bad Input..\nex)\n./RPN \"1 2 + 3 4 +*\"");
    else
    {
        this->input = argv[1];

        std::string valid_string = "0123456789+-/* ";
        std::size_t pos = this->input.find_first_of(valid_string);
        if (pos != std::string::npos)
            throw std::string("Error: '" + this->input + "' Bad Input.. just number & four arithmetic operations");
    }
}

void Rpn::goStack(void)
{
    
}

void Rpn::run()
{
}
