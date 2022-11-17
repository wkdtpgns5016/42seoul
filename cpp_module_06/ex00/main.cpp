#include <iostream>
#include "Conversion.hpp"

int main(int ac, char **av)
{
	std::string value;

	if (ac != 2)
	{
		std::cerr << "Error: argument error!" << std::endl;
		return (1);
	}
	value = av[1];
	Conversion conversion(value);
	std::cout << conversion << std::endl;

	return (0);
}
