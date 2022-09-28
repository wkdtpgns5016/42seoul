
#include "../include/philo.h"

void	*monitor_philo(void *data)
{
	int			i;
	int			time;
	t_monitor	*monitor;
	t_philo		**philos;
	t_info		info;

	monitor = (t_monitor *)data;
	philos = monitor->philos;
	info = monitor->philos[0]->info;
	while (check_dead(philos[0]) == 0)
	{
		i = 0;
		while (i < info.num_of_philo)
		{
			pthread_mutex_lock(philos[i]->time_mutex);
			time = calc_ms(philos[i]->starve_time);
			if (time > info.time_to_die * 1000)
			{
				dead(philos[i], time);
				pthread_mutex_unlock(philos[i]->time_mutex);
				break ;
			}
			else
				pthread_mutex_unlock(philos[i]->time_mutex);
			i++;
		}
	}
	return (0);
}

void	set_deadflag(t_philo **philos, int num)
{
	int				*deadflag;
	pthread_mutex_t	*flag_mutex;
	int				i;

	deadflag = (int *)malloc(sizeof(int));
	*deadflag = 0;
	flag_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(flag_mutex, NULL);
	i = 0;
	while (i < num)
	{
		philos[i]->dead_flag = deadflag;
		philos[i]->flag_mutex = flag_mutex;
		i++;
	}
}

t_monitor	set_monitor(pthread_mutex_t **fork, t_info info)
{
	t_monitor		monitor;
	t_time			*time;
	struct timeval	start_time;
	int				i;

	monitor.monitor = (pthread_t *)malloc(sizeof(pthread_t));
	monitor.philos = (t_philo **)malloc(sizeof(t_philo *) * info.num_of_philo);
	time = set_time();
	time->timestamp = &start_time;
	gettimeofday(time->timestamp, NULL);
	i = 0;
	while (i < info.num_of_philo)
	{
		monitor.philos[i] = set_philo(fork, i, info, time);
		i++;
	}
	set_deadflag(monitor.philos, info.num_of_philo);
	return (monitor);
}
