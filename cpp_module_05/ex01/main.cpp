#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat *bureaucrat = new Bureaucrat("boss", 1);
		Form * form = new Form("Form", 100, 170);
		bureaucrat->signForm(form);
		delete form;
		delete bureaucrat;
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	catch (Form::GradeTooHighException e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	catch (Form::GradeTooLowException e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}