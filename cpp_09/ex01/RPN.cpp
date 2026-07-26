#include "RPN.hpp"


RPN::RPN() {}

RPN::RPN(const RPN &copy)
    : _stack(copy._stack)
{}

RPN &RPN::operator=(const RPN &copy)
{
    if (this != &copy)
        _stack = copy._stack;
    return *this;
}

RPN::~RPN()
{
}

bool IsToken(const char &c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

void RPN::ApplyToken(std::stack<int> &_stackCopy, const char &c)
{
    if (_stackCopy.size() < 2)
        throw std::runtime_error("Error");
    int a = _stackCopy.top();
    _stackCopy.pop();
    int b = _stackCopy.top();
    _stackCopy.pop();
    if (c == '+')
        _stackCopy.push(a + b);
    if (c == '-')
        _stackCopy.push(b - a);
    if (c == '*')
        _stackCopy.push(b * a);
    if (c == '/')
    {
        if (a == 0)
            throw std::runtime_error("Error");
        _stackCopy.push(b / a);
    }
}

bool ValidChar(const char &c)
{
    if (!IsToken(c) && !isdigit(c) && c != ' ')
        return false;
    return true;
}

void RPN::Calculate(const std::string &expression)
{
    try
    {
        for (size_t i = 0; i < expression.length(); i++)
        {
            if (!ValidChar(expression[i]))
                throw std::runtime_error("Error");
            if (expression[i] == ' ')
                continue;
            if (std::isdigit(expression[i]))
            {
                if (i + 1 < expression.length() && std::isdigit(expression[i + 1]))
                    throw std::runtime_error("Error");
                _stack.push(expression[i] - '0');
            }
            else
                ApplyToken(_stack, expression[i]);
        }
        if (_stack.size() != 1)
            throw std::runtime_error("Error");
        std::cout << _stack.top() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error" << std::endl;
    }
}
