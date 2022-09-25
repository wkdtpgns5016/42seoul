
#include "../include/philo.h"

void	*monitor_philo(void *data)
{
	int		i;
	int		time;
	t_table	*table;

	table = (t_table *)data;
	while (1)
	{
		i = 0;
		pthread_mutex_lock(table->monitor->flag_mutex);
		time = calc_time(table, table->starve_time);
		if (time > table->info.time_to_die)
		{
			dead(table);
			while (i < table->info.num_of_philo)
			{
				pthread_detach(*(table->monitor->philos[i++]));
			}
			exit(1);
		}
		pthread_mutex_unlock(table->monitor->flag_mutex);
	}
	return (0);
}

t_monitor	set_monitor(pthread_t **philos)
{
	t_monitor	monitor;

	monitor.monitor = (pthread_t *)malloc(sizeof(pthread_t));
	monitor.flag_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(monitor.flag_mutex, NULL);
	monitor.dead_flag = 0;
	monitor.philos = philos;
	monitor.time = 0;
	return (monitor);
}
