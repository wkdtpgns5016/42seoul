#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>

struct Data
{
	std::string name;
	int age;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

std::ostream& operator<<(std::ostream& os, const Data& data);

#endif