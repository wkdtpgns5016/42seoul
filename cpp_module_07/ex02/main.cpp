#include <Array.hpp>
#include <iostream>

int main()
{
	std::cout << "================int=================" << std::endl;
	Array<int> arr(3);
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	for (int i=0; i<3; i++)
		std::cout << arr[0] << " ";
	std::cout << std::endl;

	return (0);
}