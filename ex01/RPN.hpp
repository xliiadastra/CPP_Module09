#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <stack>
# include <iterator>

class Rpn
{
private:
    std::string     input;
    std::stack<float> number;

    Rpn(const Rpn& orig) { *this = orig; };
    Rpn& operator=(const Rpn& orig) { if (this != &orig) this->input = orig.input; return *this; };
    std::string ft_trim(std::string str);

public:
    Rpn();
    ~Rpn();

    void    validArgv(int argc, char* argv[]);
    void    goStack();
};

#endif
