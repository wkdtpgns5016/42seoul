#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

class Bureaucrat;
class RobotomyRequestForm : public Form
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& form);
		virtual ~RobotomyRequestForm();

		const RobotomyRequestForm& operator=(const RobotomyRequestForm& form);
		std::string getTarget(void) const;
		virtual void execute(Bureaucrat const & executor) const;
};

#endif