#include "../include/philo.h"

int	check_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->flag_mutex);
	if (*philo->dead_flag)
	{
		pthread_mutex_unlock(philo->flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->flag_mutex);
	return (0);
}

void	dead(t_philo *philo, uint64_t time)
{
	pthread_mutex_lock(philo->flag_mutex);
	print_message("is dead", philo->philo_num + 1, time);
	*philo->dead_flag = 1;
	pthread_mutex_unlock(philo->flag_mutex);
}
