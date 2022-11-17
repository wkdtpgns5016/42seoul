#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
	private:
		unsigned int _size;
		T* _data;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& array);
		~Array();
		const Array& operator=(const Array& array);
		T& operator[](unsigned int idx);
		unsigned int size() const;
};

#endif