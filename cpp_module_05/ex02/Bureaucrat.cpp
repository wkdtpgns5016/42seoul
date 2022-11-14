#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("name"), _grade(150)
{
	
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : _name(bureaucrat.getName()), _grade(bureaucrat.getGrade())
{

}

Bureaucrat::~Bureaucrat()
{

}

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	if (this != &bureaucrat)
	{
		*(const_cast<std::string *>(&this->_name)) = bureaucrat.getName();
		this->_grade = bureaucrat.getGrade();
	}
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch(Form::GradeTooLowException e)
	{
		std::cerr << *this << " couldn’t sign " << form << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		std::cout << *this << " excuted " << form << std::endl;
		form.execute(*this);
	}
	catch(Form::GradeTooLowException e)
	{
		std::cerr << *this << " couldn’t excuted " << form << " because " << e.what() << std::endl;
	}
	catch(Form::NotSignException e)
	{
		std::cerr << *this << " couldn’t excuted " << form << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bureaucrat)
{
	return (o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}
