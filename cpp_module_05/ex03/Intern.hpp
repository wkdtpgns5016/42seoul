#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& intern);
		~Intern();

		const Intern& operator=(const Intern& intern);
		int getIndexName(std::string name);
		Form* createSF(const std::string& target);
		Form* createRF(const std::string& target);
		Form* createPF(const std::string& target);
		Form* createNULL(const std::string& target);
		Form* makeForm(const std::string& name, const std::string& target);
};

#endif