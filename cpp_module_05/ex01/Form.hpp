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
		const int _signGrade;
		const int _executeGrade;

	public:
		Form();
		Form(const std::string& name, const int& signGrade, const int& executeGrade);
		Form(const Form& form);
		~Form();

		const Form& operator=(const Form& form);
		std::string getName(void) const;
		bool getSign(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;
		void beSigned(Bureaucrat bureaucrat);

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
};

std::ostream& operator<<(std::ostream& o, const Form& form);

#endif