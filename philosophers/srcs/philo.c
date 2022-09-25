
#include "../include/philo.h"

void	*action(void *data)
{
	t_table			*table;

	table = (t_table *)data;
	gettimeofday(&(table->starve_time), NULL);
	while (1)
	{
		if (pick_up_fork(table))
			break ;
		if (eating(table))
			break ;
		if (put_down_fork(table))
			break ;
		if (sleeping(table))
			break ;
		if (thinking(table))
			break ;
	}
	return (0);
}

t_table	*make_table(t_table table)
{
	t_table	*new;

	new = (t_table *)malloc(sizeof(t_table) * table.info.num_of_philo);
	new->fork = table.fork;
	new->info = table.info;
	new->time_mutex = table.time_mutex;
	new->time = table.time;
	new->monitor = table.monitor;
	return (new);
}

void	create_philos(pthread_t **philos, t_table table)
{
	int			i;
	int			num_of_philo;
	t_table		*new;

	i = 0;
	num_of_philo = table.info.num_of_philo;
	gettimeofday(&table.time, NULL);
	while (i < num_of_philo)
	{
		new = make_table(table);
		new->philo_num = i + 1;
		new->left_fork = get_left_fork(new->philo_num, num_of_philo);
		new->right_fork = get_right_fork(new->philo_num);
		pthread_create(philos[i], NULL, action, (void *)new);
		pthread_create(table.monitor->monitor, NULL, monitor_philo, (void *)new);
		i++;
	}
}

pthread_t	**set_philo(t_table table)
{
	pthread_t	**philos;
	int			num_of_philo;
	int			i;

	num_of_philo = table.info.num_of_philo;
	i = 0;
	philos = (pthread_t **)malloc(sizeof(pthread_t *) * num_of_philo);
	while (i < num_of_philo)
	{
		philos[i] = (pthread_t *)malloc(sizeof(pthread_t));
		i++;
	}
	return (philos);
}
