#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Bureaucrat *bureaucrat = new Bureaucrat("boss", 1);
		Bureaucrat *a = new Bureaucrat("bab", 72);
		Intern someRandomIntern;
		Form* rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		std::cout << "=================================" << std::endl;
		a->signForm(*rrf);
		std::cout << "=================================" << std::endl;
		bureaucrat->executeForm(*rrf);
		std::cout << "=================================" << std::endl;
		
		delete rrf;
		delete a;
		delete bureaucrat;
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}