#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& intern)
{
	(void)intern;
}

Intern::~Intern()
{

}

const Intern& Intern::operator=(const Intern& intern)
{
	(void)intern;
	return (*this);
}

int	Intern::getIndexName(std::string name)
{
	int i = 0;
	int flag = 1;
	std::string names[3];

	names[0] = "shrubbery creation";
	names[1] = "robotomy request";
	names[2] = "presidential pardon";
	while (flag != 0 && i < 3)
	{
		flag = names[i].compare(name);
		i++;
	}
	return (i - 1);
}

Form* Intern::createSF(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

Form* Intern::createRF(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

Form* Intern::createPF(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

Form* Intern::createNULL(const std::string& target)
{
	(void)target;
	return (NULL);
}

Form* Intern::makeForm(const std::string& name, const std::string& target)
{
	Form* form;
	Form* (Intern::*f[4])(const std::string& target);
	int idx;

	f[0] = &Intern::createSF;
	f[1] = &Intern::createRF;
	f[2] = &Intern::createPF;
	f[3] = &Intern::createNULL;
	idx = getIndexName(name);
	form = (this->*f[idx])(target);
	return (form);
}
