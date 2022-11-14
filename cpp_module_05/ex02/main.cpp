#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat *bureaucrat = new Bureaucrat("boss", 1);
		Bureaucrat *a = new Bureaucrat("bab", 100);
		Bureaucrat *b = new Bureaucrat("mark", 70);
		Bureaucrat *c = new Bureaucrat("jam", 10);
		Form *form = new ShrubberyCreationForm("trees");
		Form *form2 = new RobotomyRequestForm("papago");
		Form *form3 = new PresidentialPardonForm("jake");

		std::cout << "=================================" << std::endl;
		a->signForm(*form);
		b->signForm(*form2);
		c->signForm(*form3);
		std::cout << "=================================" << std::endl;
		bureaucrat->executeForm(*form);
		bureaucrat->executeForm(*form2);
		bureaucrat->executeForm(*form3);
		std::cout << "=================================" << std::endl;

		delete form;
		delete form2;
		delete form3;
		delete a;
		delete b;
		delete c;
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