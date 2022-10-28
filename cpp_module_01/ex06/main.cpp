#include "Harl.hpp"

int check_arg(int ac, char **av)
{
	std::string level;

	if (ac != 2)
		return 1;
	level = av[1];
	if (level.compare("DEBUG") != 0 && level.compare("INFO") != 0 && \
	level.compare("WARNING") != 0 && level.compare("ERROR") != 0)
		return 1;
	return 0;
}

int main(int ac, char **av)
{
	if (check_arg(ac, av))
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		exit(1);
	}
	Harl harl;
	harl.complain(av[1]);

}