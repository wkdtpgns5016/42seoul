#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain& brain);
		~Brain();

		const Brain& operator=(const Brain& brain);
		std::string getIdea(int idx) const;
		void setIdea(int idx, std::string idea);
};

#endif