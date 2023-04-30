#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <iterator>

class Rpn
{
private:
    std::string   input;
    std::stack<int>     calculator;

public:
    Rpn();
    Rpn(Rpn& orig);
    Rpn& operator=(const Rpn& orig);
    ~Rpn();

    void    validArgv(const int argc, const char* argv[]);
    void    goStack();
    void    run();
};

#endif
