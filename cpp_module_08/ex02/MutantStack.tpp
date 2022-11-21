#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& mutantStack)
{
	(void)mutantStack;
}

template <typename T>
MutantStack<T>::~MutantStack()
{

}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& mutantStack)
{
	(void)mutantStack;
	return (*this);
}

template <typename T>
typename MutantStack<T>::stack::container_type::iterator MutantStack<T>::begin(void) 
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::stack::container_type::iterator MutantStack<T>::end(void) 
{
	return (this->c.end());
}