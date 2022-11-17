#include "Serialization.hpp"

int main()
{
	Data human;
	uintptr_t raw;
	Data* ptr;

	human.name = "bob";
	human.age = 20;

	raw = serialize(&human);
	ptr = deserialize(raw);
	std::cout << "Serialized: " << raw << std::endl;
	std::cout << "Deserialized: " << *ptr << std::endl;
	std::cout << "Human address: " << &human << std::endl;
	std::cout << "Ptr address: " << ptr << std::endl;
	return (0);
}