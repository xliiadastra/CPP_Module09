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

    std::string ft_trim(std::string str);
public:
    Rpn();
    Rpn(Rpn& orig);
    Rpn& operator=(const Rpn& orig);
    ~Rpn();

    void    validArgv(int argc, char* argv[]);
    void    goStack();
    void    run();
};

#endif
