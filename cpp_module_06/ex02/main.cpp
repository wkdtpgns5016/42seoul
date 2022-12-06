#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
	int ran;

	ran = rand() % 3;
	switch (ran)
	{
		case 0:
			return (new A());
			break;

		case 1:
			return (new B());
			break;

		case 2:
			return (new C());
			break;

		default:
			return (NULL);
			break;
	}
}

void identify(Base* p)
{
	std::cout << "identify ptr: ";
	if (p == NULL)
		std::cout << "NULL";
	else if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	std::cout << std::endl;
}

void identify(Base& p)
{
	std::cout << "identify ref: ";
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "A";
		(void)a;
	}
	catch(const std::exception& e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			std::cout << "B";
			(void)b;
		}
		catch(const std::exception& e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				std::cout << "C";
				(void)c;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what();
			}
		}
	}
	std::cout << std::endl;
}

int main()
{
	srand((unsigned int)time(NULL));
	for (int i=0; i<5; i++)
	{
		Base* bPtr = generate();
		Base& bRef = *bPtr;
		identify(bPtr);
		identify(bRef);
		delete bPtr;
		std::cout << std::endl;
	}
	return (0);
}