#include "Form.hpp"

Form::Form() : _name("Form"), _sign(false), _signGrade(150), _executeGrade(150)
{

}

Form::Form(const std::string& name, const int& signGrade, const int& executeGrade) : _name(name), _sign(false)
{
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else
	{
		*(const_cast<int *>(&this->_signGrade)) = signGrade;
		*(const_cast<int *>(&this->_executeGrade)) = executeGrade;
	}
}

Form::Form(const Form& form) : _name(form.getName()), _sign(form.getSign()), _signGrade(form.getSignGrade()), _executeGrade(form.getExecuteGrade())
{
	
}

Form::~Form()
{

}

const Form& Form::operator=(const Form& form)
{
	if (this != &form)
	{
		*(const_cast<std::string *>(&this->_name)) = form.getName();
		*(const_cast<int *>(&this->_signGrade)) = form.getSignGrade();
		this->_sign = form.getSign();
		*(const_cast<int *>(&this->_executeGrade)) = form.getExecuteGrade();
	}
	return (*this);
}

std::string Form::getName(void) const
{
	return (this->_name);
}

bool Form::getSign(void) const
{
	return (this->_sign);
}

int Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int Form::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

void Form::beSigned(Bureaucrat bureaucrat)
{
	if (this->_signGrade < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	else
	{
		this->_sign = true;
	}
}

const std::string Form::GradeTooLowException::what()
{
	return ("Grade is too low.");
}

const std::string Form::GradeTooHighException::what(void)
{
	return ("Grade is too high.");
}

const std::string Form::NotSignException::what()
{
	return ("This Form isn't signed.");
}

std::ostream& operator<<(std::ostream& o, const Form& form)
{
	return (o << form.getName() << ", Required grades: sign " << form.getSignGrade()<< ", exec " << form.getExecuteGrade());
}