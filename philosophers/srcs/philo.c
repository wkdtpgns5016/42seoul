#include "./include/philo.h"

void	philo(int ac, char **av)
{

}

int	main(int ac, char **av)
{
	if (ac == 4 || ac == 5)
		philo(ac, av);
	else
		printf("Arguments Error\n");
	return (0);
}
