#include "RPN.hpp"

Rpn::Rpn() : input("") {}

Rpn::Rpn(Rpn& orig)
{
    (void)orig;
}

Rpn& Rpn::operator=(const Rpn& orig)
{
    (void)orig;
    return *this;
}

Rpn::~Rpn()
{
}

std::string Rpn::ft_trim(std::string str)
{
    std::string valid_string = " ";
//    std::size_t pos = str.find_first_not_of(valid_string);
//    int num_fl = 0;

    str.erase(0, str.find_first_not_of(valid_string));
    while (std::isspace(str.back()))
        str.erase(str.find_last_not_of(valid_string) + 1, str.length() - 1);

    // for (std::size_t i = 0; i < str.length(); ++i)
    // {
    //     if (str[i] == ' ')
    //         continue;
    //     if (std::isdigit(str[i]))
    //     {
    //         ++num_fl;
    //         if (num_fl > 2)
    //             throw std::string("Error: It is not reverse Polish notation.");
    //     }
    //     else
    //         num_fl = 0;
    // }

    return str;
}

void Rpn::validArgv(int argc, char* argv[])
{
    if (argc != 2)
        throw std::string("Error: Bad Input..\nex) ./RPN \"1 2 + 3 4 +*\"");
    else
    {
        std::string str = argv[1];

        std::string valid_string = "0123456789+-/* ";
        std::size_t pos = str.find_first_not_of(valid_string);
        if (pos != std::string::npos)
            throw std::string("Error: '" + str + "' Bad Input.. just integer & four arithmetic operations");
        else
            this->input = this->ft_trim(str);
    }
}

void Rpn::goStack(void)
{
    for (std::size_t i = 0; i < this->input.length(); ++i)
    {
        if (this->input[i] == ' ')
            continue;
        else if (std::isdigit(this->input[i]) && this->input[i + 1] == ' ')
            this->number.push(input[i] - '0');
        else
        {
            if (this->number.size() < 2)
                throw std::string("Error: It is not reverse Polish notation.");
            float a = this->number.top();
            this->number.pop();
            float b = this->number.top();
            this->number.pop();
            if (a == 0 && this->input[i] == '/')
                throw std::string("NaN");
            if (this->input[i] == '+')
                this->number.push(b + a);
            else if (this->input[i] == '-')
                this->number.push(b - a);
            else if (this->input[i] == '/') // 생각해보니 float 써야 나누셈 받을 수 있지 않음?ㅋ
                this->number.push(b / a);
            else if (this->input[i] == '*')
                this->number.push(b * a);
            else
                throw std::string("Error: It is not reverse Polish notation.");
        }
    }
    if (this->number.size() != 1)
        throw std::string("Error: It is not reverse Polish notation.");
    std::cout << this->number.top() << std::endl;
}

void Rpn::run()
{
}
