#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _data(NULL)
{

}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _data(new T[n])
{
	
}

template <typename T>
Array<T>::Array(const Array& array) : _size(array._size), _data(new T[array._size])
{
	for (unsigned int i=0; i<array._size; i++)
		this->_data[i] = array._data[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_data;
}

template <typename T>
const Array& Array<T>::operator=(const Array& array)
{
	if (this != &array)
	{
		this->_size = array._size;
		this->_data = new T[array._size];
		for (unsigned int i=0; i<array._size; i++)
			this->_data[i] = array._data[i];
	}
	(*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
	if (idx >= 0 && idx < this->_size)
	{
		return (this->_data[idx]);
	}
	else
		throw std::out_of_range("out_of_range");
	
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}
