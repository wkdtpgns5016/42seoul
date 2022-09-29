#include "../include/philo.h"

int	put_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork[philo->left_fork]);
	pthread_mutex_unlock(philo->fork[philo->right_fork]);
	return (0);
}

int	pick_up_fork(t_philo *philo)
{
	uint64_t	time;

	if (philo->philo_num % 2 == 0)
	{
		pthread_mutex_lock(philo->fork[philo->left_fork]);
		pthread_mutex_lock(philo->fork[philo->right_fork]);
	}
	else
	{
		pthread_mutex_lock(philo->fork[philo->right_fork]);
		pthread_mutex_lock(philo->fork[philo->left_fork]);
	}
	pthread_mutex_lock(philo->print_mutex);
	if (check_dead(philo))
	{
		put_down_fork(philo);
		pthread_mutex_unlock(philo->print_mutex);
		return (1);
	}
	time = calc_ms(philo->timestamp);
	print_message("is has taken a fork", philo->philo_num + 1, time);
	pthread_mutex_unlock(philo->print_mutex);
	return (0);
}

int	eating(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(philo->print_mutex);
	if (check_dead(philo))
	{
		pthread_mutex_unlock(philo->print_mutex);
		return (1);
	}
	time = calc_ms(philo->timestamp);
	print_message("is eating", philo->philo_num + 1, time);
	pthread_mutex_unlock(philo->print_mutex);
	ft_sleep(philo->info.time_to_eat * 1000);
	pthread_mutex_lock(philo->last_eat_mutex);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(philo->last_eat_mutex);
	return (0);
}

int	sleeping(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(philo->print_mutex);
	if (check_dead(philo))
	{
		pthread_mutex_unlock(philo->print_mutex);
		return (1);
	}
	time = calc_ms(philo->timestamp);
	print_message("is sleeping", philo->philo_num + 1, time);
	pthread_mutex_unlock(philo->print_mutex);
	ft_sleep(philo->info.time_to_sleep * 1000);
	return (0);
}

int	thinking(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(philo->print_mutex);
	if (check_dead(philo))
	{
		pthread_mutex_unlock(philo->print_mutex);
		return (1);
	}
	time = calc_ms(philo->timestamp);
	print_message("is thinking", philo->philo_num + 1, time);
	pthread_mutex_unlock(philo->print_mutex);
	return (0);
}
