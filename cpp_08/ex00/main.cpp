#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
    std::cout << "========== VECTOR ==========" << std::endl;

    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        easyfind(vec, 99);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== LIST ==========" << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 15);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== DEQUE ==========" << std::endl;

    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_back(4);

    try
    {
        std::deque<int>::iterator it = easyfind(deq, 4);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== MODIFY ==========" << std::endl;

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 20);
        *it = 200;

        for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
            std::cout << *i << " ";
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}