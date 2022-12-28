#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain's constructor called." << std::endl;
}

Brain::Brain(const Brain& brain)
{
	for (int i=0; i<100; i++)
		this->_ideas[i] = brain._ideas[i];
	std::cout << "Brain's copy constructor called." << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain's destructor called." << std::endl;
}

const Brain& Brain::operator=(const Brain& brain)
{
	if (this != &brain)
	{
		for (int i=0; i<100; i++)
			this->_ideas[i] = brain._ideas[i];
		std::cout << "Cat's Copy assignment operator called." << std::endl;
	}
	return (*this);
}

std::string Brain::getIdea(int idx) const
{
	return (this->_ideas[idx]);
}

void Brain::setIdea(int idx, std::string idea)
{
	this->_ideas[idx] = idea;
}