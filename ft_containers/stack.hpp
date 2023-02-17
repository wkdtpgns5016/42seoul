#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{

template <class T, class Container = ft::vector<T> >
class stack
{
	public:
	typedef T									value_type;
	typedef Container							container_type;
	typedef size_t								size_type;

	typedef typename Container::reference		reference;
	typedef typename Container::const_reference	const_reference;

	protected:
	container_type _c;

	public:
	stack (const container_type& ctnr = container_type()) : _c(ctnr) {}

	bool empty() const { return (_c.empty()); }
	size_type size() const { return (_c.size()); }
	reference top() { return (_c.back()); }
	const_reference top() const { return (_c.back()); }
	void push(const value_type& val) { _c.push_back(val); }
	void pop() { _c.pop_back(); }

	container_type get_container() const { return (_c); }
};


template <class T, class Container>
bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (lhs.get_container() == rhs.get_container());
}

template <class T, class Container>
bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return !(lhs == rhs);
}

template <class T, class Container>
bool operator< (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (lhs.get_container() < rhs.get_container());
}

template <class T, class Container>
bool operator> (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (rhs < lhs);
}

template <class T, class Container>
bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return !(rhs < lhs);
}

template <class T, class Container>
bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return !(lhs < rhs);
}
}

#endif