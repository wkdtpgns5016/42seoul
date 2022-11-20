#include "Span.hpp"

Span::Span() : _n(1)
{

}

Span::Span(unsigned int n) : _n(n)
{
	
}

Span::Span(const Span& span) : _n(span._n), _vec(span._vec)
{
	
}

Span::~Span()
{
	
}

Span& Span::operator=(const Span& span)
{
	if (this != &span)
	{
		this->_n = span._n;
		this->_vec = span._vec;
	}
	return (*this);
}

void Span::addNumber(int num)
{
	if (this->_n == this->_vec.size())
		throw std::out_of_range("There's not enough space");
	this->_vec.push_back(num);
}

unsigned int Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw std::out_of_range("There's not enough space");
	
	std::vector<int> sortVec = this->_vec;
	unsigned int ret = UINT_MAX;
	int prev;

	std::sort(sortVec.begin(), sortVec.end());
	for (std::vector<int>::iterator iter = sortVec.begin(); iter != sortVec.end(); iter++) 
	{
		if (iter == sortVec.begin()) 
			prev = *iter;
		else 
		{
			if (ret > (unsigned int)(*iter - prev)) 
				ret = (unsigned int)(*iter - prev);
			prev = *iter;
		}
	}
	return (ret);
}

unsigned int Span::longestSpan()
{
	if (_vec.size() < 2)
		throw std::out_of_range("There's not enough space");

	int min = *std::min_element(_vec.begin(), _vec.end());
	int max = *std::max_element(_vec.begin(), _vec.end());
	return (max - min);
}
