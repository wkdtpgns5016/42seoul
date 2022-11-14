#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class PresidentialPardonForm : public Form
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& form);
		virtual ~PresidentialPardonForm();

		const PresidentialPardonForm& operator=(const PresidentialPardonForm& form);
		std::string getTarget(void) const;
		virtual void execute(Bureaucrat const & executor) const;

};

#endif