#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	int i = rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {}
}

int main()
{
    std::cout << "========== RANDOM TEST ==========" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        Base *obj = generate();

        std::cout << "Pointer  : ";
        identify(obj);

        std::cout << "Reference: ";
        identify(*obj);

        delete obj;

        std::cout << "------------------------" << std::endl;
    }

    std::cout << "\n========== MANUAL TEST ==========" << std::endl;

    Base *a = new A();
    Base *b = new B();
    Base *c = new C();

    std::cout << "A pointer      : ";
    identify(a);

    std::cout << "A reference    : ";
    identify(*a);

    std::cout << "B pointer      : ";
    identify(b);

    std::cout << "B reference    : ";
    identify(*b);

    std::cout << "C pointer      : ";
    identify(c);

    std::cout << "C reference    : ";
    identify(*c);

    delete a;
    delete b;
    delete c;

    return 0;
}