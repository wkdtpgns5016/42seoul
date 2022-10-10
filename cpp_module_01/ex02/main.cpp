#include <iostream>

int main(void) {
	std::string A = "HI THIS IS BRAIN";
	std::string *stringPTR = &A;
	std::string &stringREF = A;

	std::cout << "======================================================" << std::endl;
	std::cout << "The memory address of the string variable : " << &A << std::endl;
	std::cout << "The memory address held by stirngPTR : " << stringPTR << std::endl;
	std::cout << "The memory address held by stirngREF : " << &stringREF << std::endl;
	std::cout << "======================================================" << std::endl;

	std::cout << "The value of the string variable : " << A << std::endl;
	std::cout << "The value pointed to by stirngPTR : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stirngREF : " << stringREF << std::endl;
	std::cout << "======================================================" << std::endl;

	std::string B = "THE STRING IS CHANGED";
	stringPTR = &B;

	std::cout << "The memory address of the string variable : " << &A << std::endl;
	std::cout << "The memory address held by stirngPTR : " << stringPTR << std::endl;
	std::cout << "The memory address held by stirngREF : " << &stringREF << std::endl;
	std::cout << "======================================================" << std::endl;

	//stringPTR = &A;

	std::cout << "The value of the string variable : " << A << std::endl;
	std::cout << "The value pointed to by stirngPTR : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stirngREF : " << stringREF << std::endl;
	std::cout << "======================================================" << std::endl;

	return 0;
}