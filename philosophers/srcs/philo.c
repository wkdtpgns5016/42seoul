
#include "../include/philo.h"

void	*action(void *data)
{
	t_philo			*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(philo->last_eat_mutex);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(philo->last_eat_mutex);
	if (philo->philo_num % 2 == 0)
		ft_sleep((philo->info.time_to_eat / 2) * 1000);
	while (1)
	{
		if (pick_up_fork(philo))
			break ;
		if (eating(philo))
			break ;
		if (put_down_fork(philo))
			break ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
	return (0);
}

void	create_philo_thread(t_monitor monitor, t_info info)
{
	int	total;
	int	i;

	total = info.num_of_philo;
	i = 0;
	while (i < total)
	{
		pthread_create(monitor.philos[i]->philo, NULL, action, (void *)monitor.philos[i]);
		i++;
	}
}

t_philo	*set_philo(pthread_mutex_t **fork, int num, t_info info, t_time *time)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->dead_flag = 0;
	philo->fork = fork;
	philo->philo_num = num;
	philo->left_fork = get_left_fork(num, info.num_of_philo);
	philo->right_fork = get_right_fork(num);
	philo->philo = (pthread_t *)malloc(sizeof(pthread_t));
	philo->timestamp = *(time->timestamp);
	philo->print_mutex = time->time_mutex;
	philo->last_eat_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo->last_eat_mutex, NULL);
	philo->info = info;
	return (philo);
}
