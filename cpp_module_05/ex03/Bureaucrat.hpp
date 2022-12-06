#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;
class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, const int& grade);
		Bureaucrat(const Bureaucrat& bureaucrat);
		~Bureaucrat();

		const Bureaucrat& operator=(const Bureaucrat& bureaucrat);
		std::string getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(Form& form);
		void executeForm(Form const & Form);

		class GradeTooLowException
		{
			public:
				const std::string what(void);
		};
		class GradeTooHighException
		{
			public:
				const std::string what(void);
		};
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bureaucrat);

#endif