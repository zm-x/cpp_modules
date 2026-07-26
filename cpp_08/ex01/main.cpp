#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
    std::cout << "========== SUBJECT TEST ==========" << std::endl;

    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest : " << sp.longestSpan() << std::endl;

    std::cout << "\n========== FULL SPAN ==========" << std::endl;

    try
    {
        sp.addNumber(42);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== EMPTY SPAN ==========" << std::endl;

    try
    {
        Span empty(5);
        std::cout << empty.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== ONE NUMBER ==========" << std::endl;

    try
    {
        Span one(5);
        one.addNumber(10);
        std::cout << one.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== 10000 NUMBERS ==========" << std::endl;

    Span big(10000);

    std::srand(std::time(NULL));

    for (int i = 0; i < 10000; i++)
        big.addNumber(std::rand());

    std::cout << "Shortest: " << big.shortestSpan() << std::endl;
    std::cout << "Longest : " << big.longestSpan() << std::endl;

    return 0;
}