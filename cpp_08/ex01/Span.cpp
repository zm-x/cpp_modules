#include "Span.hpp"

Span::Span(unsigned int maxsize) 
    : _MaxSize(maxsize) {}

Span::Span(const Span &copy) 
    : _MaxSize(copy._MaxSize), _Numbers(copy._Numbers) {}

Span::~Span() {}

Span &Span::operator=(const Span &to_copy)
{
    if (this != & to_copy)
    {
        _MaxSize = to_copy._MaxSize;
        _Numbers = to_copy._Numbers;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (_Numbers.size() == _MaxSize)
        throw FullSpanException();
    _Numbers.push_back(number);
}

int Span::shortestSpan() const
{
    int shortest_span;
    std::vector<int> temp = _Numbers;
    if (temp.size() < 2)
        throw NoSpanException();
    std::sort(temp.begin(), temp.end());
    shortest_span = temp[1] - temp[0];
    for (unsigned int i = 0; i < temp.size() - 1; i++)
    {
        if ((temp[i + 1] - temp[i]) < shortest_span)
            shortest_span = temp[i + 1] - temp[i];
    }
    return shortest_span;
}

int Span::longestSpan() const
{
    if (_Numbers.size() < 2)
        throw NoSpanException();
    return (*std::max_element(_Numbers.begin(), _Numbers.end()) - *std::min_element(_Numbers.begin(), _Numbers.end()));
}

const char *Span::FullSpanException::what() const throw()
{
    return "Span is full";
}

const char *Span::NoSpanException::what() const throw()
{
    return "Not enough numbers to find a span";
}
