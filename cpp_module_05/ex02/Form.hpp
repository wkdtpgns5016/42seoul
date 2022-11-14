#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
		const std::string _name;
		bool _sign;
		int _signGrade;
		int _executeGrade;

	public:
		Form();
		Form(const std::string& name, const int& signGrade, const int& executeGrade);
		Form(const Form& form);
		virtual ~Form();

		const Form& operator=(const Form& form);
		std::string getName(void) const;
		bool getSign(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;
		void beSigned(Bureaucrat bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;

		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NotSignException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& o, const Form& form);

#endif