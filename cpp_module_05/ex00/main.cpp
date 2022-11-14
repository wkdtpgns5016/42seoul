#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat *bureaucrat = new Bureaucrat("boss", 1);
		std::cout << *bureaucrat << std::endl;
		delete bureaucrat;
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}