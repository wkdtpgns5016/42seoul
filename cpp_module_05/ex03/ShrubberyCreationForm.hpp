#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;
class ShrubberyCreationForm : public Form
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& form);
		virtual ~ShrubberyCreationForm();

		const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);
		std::string getTarget(void) const;
		virtual void execute(Bureaucrat const & executor) const;

};

#endif