#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <string>
#include <stdlib.h>

class RPN
{
private:
    std::stack<int> _stack;

public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    void Calculate(const std::string &expression);
    void ApplyToken(std::stack<int> &_stackCopy, const char &c);
};

#endif