#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& mutantStack);
		~MutantStack();

		MutantStack& operator=(const MutantStack& mutantStack);
		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"

#endif