#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : \
Form("PresidentialPardonForm", 25, 5), _target("target")
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : \
Form("PresidentialPardonForm", 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form) : \
Form("PresidentialPardonForm", 25, 5), _target(form.getTarget())
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& form)
{
	this->_target = form.getTarget();
	Form::operator=(form);
	return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() != true)
		throw Form::NotSignException();
	if (this->getExecuteGrade() < executor.getGrade())
		throw Form::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
