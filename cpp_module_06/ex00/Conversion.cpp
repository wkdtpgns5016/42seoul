#include "Conversion.hpp"

Conversion::Conversion() : _value("0"), _doubleValue(0)
{
	
}

Conversion::Conversion(const std::string& value) : _value(value)
{
	double doubleValue;
	char* pos = NULL;

	if (value.length() == 1 && !isdigit(value[0]))
		doubleValue = static_cast<double>(value[0]);
	else
		doubleValue = strtod(value.c_str(), &pos);
	this->_doubleValue = doubleValue;
}

Conversion::Conversion(const Conversion& conversion) : _value(conversion._value), _doubleValue(conversion._doubleValue)
{
	
}

Conversion::~Conversion()
{
	
}

Conversion& Conversion::operator=(const Conversion& conversion)
{
	if (this != &conversion)
	{
		this->_value = conversion._value;
		this->_doubleValue = conversion._doubleValue;
	}
	return (*this);
}

std::string Conversion::getValue(void) const
{
	return (this->_value);
}

char Conversion::convertChar(void) const
{
	return (static_cast<char>(this->_doubleValue));
}

int Conversion::convertInt(void) const
{
	return (static_cast<int>(this->_doubleValue));
}

float Conversion::convertFloat(void) const
{
	return (static_cast<float>(this->_doubleValue));
}

double Conversion::convertDouble(void) const
{
	return (static_cast<double>(this->_doubleValue));
}

std::string Conversion::getChar(void) const
{
	std::stringstream ss;
	double doubleValue = this->convertDouble();
	char charValue;

	if (this->_value == "nanf" || this->_value == "nan")
		throw Conversion::ImpossibleException();
	else if (this->_value == "+inff" || this->_value == "-inff" || this->_value == "inff" || \
	this->_value == "+inf" || this->_value == "-inf" || this->_value == "inf")
		throw Conversion::ImpossibleException();
	if (doubleValue < 0 || doubleValue > 255)
		throw Conversion::ImpossibleException();
	charValue = this->convertChar();
	if (!std::isprint(charValue))
		throw Conversion::NonDisplayableException();
	ss << "'" << charValue << "'";
	return (ss.str());
}

std::string Conversion::getInt(void) const
{
	std::stringstream ss;
	double doubleValue = convertDouble();
	int intValue;

	if (this->_value == "nanf" || this->_value == "nan")
		throw Conversion::ImpossibleException();
	else if (this->_value == "+inff" || this->_value == "-inff" || this->_value == "inff" || \
	this->_value == "+inf" || this->_value == "-inf" || this->_value == "inf")
		throw Conversion::ImpossibleException();
	if (doubleValue >  INT32_MAX || doubleValue < INT32_MIN)
		throw Conversion::ImpossibleException();
	intValue = convertInt();
	ss << intValue;
	return (ss.str());
}

std::string Conversion::getFloat(void) const
{
	std::stringstream ss;
	float floatValue;

	if (this->_value == "nanf" || this->_value == "nan")
		ss << "nanf";
	else if (this->_value == "+inff" || this->_value == "inff" || \
	this->_value == "+inf" || this->_value == "inf")
		ss << "inff";
	else if (this->_value == "-inff" || this->_value == "-inf")
		ss << "-inff";
	else
	{
		floatValue = convertFloat();
		ss << floatValue;
		if (floatValue == static_cast<float>(convertInt()))
		{	
			if (ss.str().length() <= 6)
				ss << ".0";
		}
		ss << "f";
	}
	return (ss.str());
}

std::string Conversion::getDouble(void) const
{
	std::stringstream ss;
	double doubleValue = convertDouble();

	if (this->_value == "nanf" || this->_value == "nan")
		ss << "nan";
	else if (this->_value == "+inff" || this->_value == "inff" || \
	this->_value == "+inf" || this->_value == "inf")
		ss << "inf";
	else if (this->_value == "-inff" || this->_value == "-inf")
		ss << "-inf";
	else
	{
		ss << doubleValue;
		if (doubleValue == static_cast<double>(convertInt()))
		{	
			if (ss.str().length() <= 6)
				ss << ".0";
		}
	}
	return (ss.str());
}

std::string Conversion::getOutput(std::string str, int flag) const
{
	std::stringstream ss;

	ss << str << ": ";
	try
	{
		switch (flag)
		{
			case 0:
				ss << this->getChar();
				break;
			case 1:
				ss << this->getInt();
				break;
			case 2:
				ss << this->getFloat();
				break;
			case 3:
				ss << this->getDouble();
				break;
			default:
				break;
		}
	}
	catch (Conversion::ImpossibleException e)
	{
		ss << e.what();
	}
	catch (Conversion::NonDisplayableException e)
	{
		ss << e.what();
	}
	ss << "\n";
	return (ss.str());
}

const char* Conversion::ImpossibleException::what() const throw() {
  return "impossible";
}

const char* Conversion::NonDisplayableException::what() const throw() {
  return "Non displayable";
}

std::ostream& operator<<(std::ostream& os, const Conversion& conversion)
{
	os << conversion.getOutput("char", 0) \
	<< conversion.getOutput("int", 1) \
	<< conversion.getOutput("float", 2) \
	<< conversion.getOutput("double", 3);
	return (os);
}