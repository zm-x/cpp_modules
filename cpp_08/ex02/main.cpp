#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << "========== SUBJECT TEST ==========" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top : " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\n========== COPY ==========" << std::endl;

    std::stack<int> s(mstack);

    std::cout << "Copied stack size: " << s.size() << std::endl;

    std::cout << "\n========== LIST COMPARISON ==========" << std::endl;

    std::list<int> lst;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    for (std::list<int>::iterator i = lst.begin(); i != lst.end(); ++i)
        std::cout << *i << std::endl;

    return 0;
}