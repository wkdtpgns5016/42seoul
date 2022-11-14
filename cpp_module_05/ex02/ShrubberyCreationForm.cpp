#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : \
Form("ShrubberyCreationForm", 145, 137), _target("target")
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : \
Form("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form) : \
Form("ShrubberyCreationForm", 145, 137), _target(form.getTarget())
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form)
{
	this->_target = form.getTarget();
	Form::operator=(form);
	return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() != true)
		throw Form::NotSignException();
	if (this->getExecuteGrade() < executor.getGrade())
		throw Form::GradeTooLowException();

	std::ofstream out(this->_target + "_Shrubbery");
   	out << "       ." << "\n" \
		<< "      ..." << "\n" \
		<< "     ....." << "\n" \
		<< "      ..." << "\n" \
		<< "     ....." << "\n" \
		<< "    ......." << "\n" \
		<< "     ....." << "\n" \
		<< "    ......." << "\n" \
		<< "   ........." << "\n" \
		<< "    ......." << "\n" \
		<< "   ........." << "\n" \
		<< "  ..........." << "\n" \
		<< "   ........." << "\n" \
		<< "  ..........." << "\n" \
		<< " ............." << "\n" \
		<< "  ..........." << "\n" \
		<< " ............." << "\n" \
		<< "..............." << "\n" \
		<< "      ###" << "\n" \
		<< "      ###" << "\n" \
		<< "      ###" << "\n" \
		<< "      ###" << "\n";
   	out.close();
}
