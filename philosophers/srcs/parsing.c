
#include "../include/philo.h"

t_info	set_info(int ac, char **av)
{
	t_info	info;
	int		i;
	int		num;

	i = 1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if (i == 1)
			info.num_of_philo = num;
		else if (i == 2)
			info.time_to_die = num;
		else if (i == 3)
			info.time_to_eat = num;
		else if (i == 4)
			info.time_to_sleep = num;
		else if (i == 5)
			info.goal = num;
		i++;
	}
	return (info);
}

pthread_mutex_t	**set_fork(int num_of_philo)
{
	pthread_mutex_t	**fork;
	int				i;

	i = 0;
	fork = \
	(pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *) * (num_of_philo));
	while (i < num_of_philo)
	{
		fork[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(fork[i], NULL);
		i++;
	}
	return (fork);
}

t_table	set_table(int ac, char **av)
{
	t_table	table;

	table.info = set_info(ac, av);
	table.fork = set_fork(table.info.num_of_philo);
	table.philo_num = 0;
	table.time_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(table.time_mutex, NULL);
	return (table);
}
