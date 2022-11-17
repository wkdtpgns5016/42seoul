#include "iter.hpp"

template <typename T>
void iter(const T arr[], int size, void (*f)(const T& t))
{
	for (int i = 0; i < size; i++)
    	f(arr[i]);
}

template <typename T>
void print(const T& t)
{
	std::cout << t << " ";
}

int main()
{
	std::cout << "================int=================" << std::endl;
	int arr[] = {0, 1, 2, 3, 4, 5};
	iter(arr, 5, print<int>);
	std::cout << std::endl;

	std::cout << "================double==============" << std::endl;
	double arr2[] = {0.1, 1.1, 2.1, 3.1, 4.1, 5.1};
	iter(arr2, 5, print<double>);
	std::cout << std::endl;

	std::cout << "================char================" << std::endl;
	char arr3[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	iter(arr3, 5, print<char>);
	std::cout << std::endl;

	std::cout << "================string===============" << std::endl;
	std::string arr4[] = {"one", "two", "three", "four", "five"};
	iter(arr4, 5, print<std::string>);
	std::cout << std::endl;
}