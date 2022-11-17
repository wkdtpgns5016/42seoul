#include "Conversion.hpp"

Conversion::Conversion() : _value("0")
{
	
}

Conversion::Conversion(const std::string& value) : _value(value)
{
	
}

Conversion::Conversion(const Conversion& conversion) : _value(conversion.getValue())
{
	
}

Conversion::~Conversion()
{
	
}

Conversion& Conversion::operator=(const Conversion& conversion)
{
	if (this != &conversion)
	{
		this->_value = conversion.getValue();
	}
	return (*this);
}

std::string Conversion::getValue(void) const
{
	return (this->_value);
}

char Conversion::convertChar(void) const
{
	int	intValue = convertInt();

	return (static_cast<char>(intValue));
}

int Conversion::convertInt(void) const
{
	int intValue;

	if (std::isdigit(this->_value[0]) || \
	((this->_value[0] == '+' || this->_value[0] == '-') && this->_value.length() > 1))
		intValue = std::strtol(this->_value.c_str(), NULL, 10);
	else
		intValue = static_cast<int>(this->_value[0]);
	return (intValue);
}

float Conversion::convertFloat(void) const
{
	float floatValue;

	if (this->_value == "-inff")
        floatValue = -std::numeric_limits<float>::infinity();
	else if (this->_value == "+inff")
	floatValue = std::numeric_limits<float>::infinity();
	else if (this->_value == "nanf")
	floatValue = std::numeric_limits<float>::quiet_NaN();
	else
	{
		if (std::isdigit(this->_value[0]) || \
		((this->_value[0] == '+' || this->_value[0] == '-') && this->_value.length() > 1))
			floatValue = std::atof(this->_value.c_str());
		else
			floatValue = static_cast<float>(this->_value[0]);

	}
	return (static_cast<float>(floatValue));
}

double Conversion::convertDouble(void) const
{
	double doubleValue;
	char* pos = NULL;
	
	if (this->_value == "-inff")
        doubleValue = -std::numeric_limits<float>::infinity();
	else if (this->_value == "+inff")
		doubleValue = std::numeric_limits<float>::infinity();
	else if (this->_value == "nanf")
		doubleValue = std::numeric_limits<float>::quiet_NaN();
	else
	{
		if (std::isdigit(this->_value[0]) || \
		((this->_value[0] == '+' || this->_value[0] == '-') && this->_value.length() > 1))
			doubleValue = std::strtod(this->_value.c_str(), &pos);
		else
			doubleValue = static_cast<double>(this->_value[0]);
	}
	return (static_cast<double>(doubleValue));
}

std::string Conversion::getChar(void) const
{
	std::stringstream ss;
	char charValue = convertChar();

	if (this->_value == "nanf" || this->_value == "nan")
		throw Conversion::ImpossibleException();
	else if (this->_value == "+inff" || this->_value == "-inff")
		throw Conversion::ImpossibleException();
	if (static_cast<int>(charValue) < 0 || static_cast<int>(charValue) > 255)
		throw Conversion::ImpossibleException();
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
	else if (this->_value == "+inff" || this->_value == "-inff")
		throw Conversion::ImpossibleException();
	if (doubleValue < std::numeric_limits<int>::lowest() || \
	doubleValue > std::numeric_limits<int>::max())
	{
		if (this->_value.compare("+inff") != 0 && \
		this->_value.compare("+inf") != 0 && \
		this->_value.compare("inff") != 0 && \
		this->_value.compare("inf") != 0 && \
		this->_value.compare("-inff") != 0 && \
		this->_value.compare("-inf") != 0)
			throw Conversion::ImpossibleException();
	}
	intValue = convertInt();
	ss << intValue;
	return (ss.str());
}

std::string Conversion::getFloat(void) const
{
	std::stringstream ss;
	double doubleValue = convertDouble();
	float floatValue;

	if (doubleValue < std::numeric_limits<float>::lowest() || \
	doubleValue > std::numeric_limits<float>::max())
	{
		if (this->_value.compare("+inff") != 0 && \
		this->_value.compare("+inf") != 0 && \
		this->_value.compare("inff") != 0 && \
		this->_value.compare("inf") != 0 && \
		this->_value.compare("-inff") != 0 && \
		this->_value.compare("-inf") != 0)
			throw Conversion::ImpossibleException();
	}
	floatValue = convertFloat();
	ss << floatValue << "f";
	return (ss.str());
}

std::string Conversion::getDouble(void) const
{
	std::stringstream ss;
	double doubleValue = convertDouble();
	
	ss << doubleValue;
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