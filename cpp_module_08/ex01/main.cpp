#include "Span.hpp"
#include <list>

int main() 
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "=================================" << std::endl;

	Span sp2 = Span(10000);
	std::vector<int> vec;
	for (int i=10000; i>=1; i--)
		vec.push_back(i);
	sp2.addNumber(vec.begin(), vec.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	std::cout << "=================================" << std::endl;

	Span sp3 = Span(3);
	sp3.addNumber(INT_MIN);
	sp3.addNumber(INT_MAX);
	sp3.addNumber(0);
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	return 0; 
}