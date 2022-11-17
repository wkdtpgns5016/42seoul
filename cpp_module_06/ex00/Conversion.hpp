#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>

class Conversion
{
	private:
		std::string _value;
		
	public:
		Conversion();
		Conversion(const std::string& value);
		Conversion(const Conversion& conversion);
		~Conversion();

		Conversion& operator=(const Conversion& conversion);
		std::string getValue(void) const;
		char convertChar(void) const;
		int convertInt(void) const;
		float convertFloat(void) const;
		double convertDouble(void) const;

		std::string getChar(void) const;
		std::string getInt(void) const;
		std::string getFloat(void) const;
		std::string getDouble(void) const;

		std::string getOutput(std::string str, int flag) const;

		class ImpossibleException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class NonDisplayableException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Conversion& conversion);

#endif