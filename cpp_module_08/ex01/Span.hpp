#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _vec;
		
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& span);
		~Span();
		Span& operator=(const Span& span);

		void addNumber(int num);
		template <typename T>
		void addNumber(const T& begin, const T& end)
		{
			unsigned int size = std::distance(begin, end);
			if (this->_n < this->_vec.size() + size)
				throw std::out_of_range("There's not enough space");
			this->_vec.insert(this->_vec.end(), begin, end);
		}

		unsigned int shortestSpan();
		unsigned int longestSpan();
};

#endif