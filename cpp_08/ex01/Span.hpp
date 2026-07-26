#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

class Span
{
    private:
        unsigned int _MaxSize;
        std::vector<int> _Numbers;
    public:
        Span(unsigned int maxsize);
        Span(const Span &copy);
        ~Span();

        Span &operator=(const Span &to_copy);

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;

        class FullSpanException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class NoSpanException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif