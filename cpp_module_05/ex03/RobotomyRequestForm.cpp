#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : \
Form("RobotomyRequestForm", 72, 45), _target("target")
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : \
Form("RobotomyRequestForm", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form) : \
Form("RobotomyRequestForm", 72, 45), _target(form.getTarget())
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form)
{
	this->_target = form.getTarget();
	Form::operator=(form);
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int num;
	
	if (this->getSign() != true)
		throw Form::NotSignException();
	if (this->getExecuteGrade() < executor.getGrade())
		throw Form::GradeTooLowException();

	srand((unsigned int)time(NULL));
	std::cout << "drilling noises..............." << std::endl;
	num = rand() % 2;
	if (num)
		std::cout << this->_target << " robotomy success." << std::endl;
	else
		std::cout << this->_target << " robotomy fail." << std::endl;
}
