#include "../include/philo.h"

int	put_down_fork(t_table *table)
{
	pthread_mutex_unlock((table->fork[table->left_fork - 1]));
	pthread_mutex_unlock((table->fork[table->right_fork - 1]));
	pthread_mutex_lock(table->monitor->flag_mutex);
	if (table->monitor->dead_flag)
	{
		pthread_mutex_unlock(table->monitor->flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(table->monitor->flag_mutex);
	gettimeofday(&(table->starve_time), NULL);
	table->monitor->time[table->info.num_of_philo] = 0;
	return (0);
}

int	pick_up_fork(t_table *table)
{
	int	time;

	if (table->philo_num % 2 == 0)
	{
		pthread_mutex_lock((table->fork[table->left_fork - 1]));
		pthread_mutex_lock((table->fork[table->right_fork - 1]));
	}
	else
	{
		pthread_mutex_lock((table->fork[table->right_fork - 1]));
		pthread_mutex_lock((table->fork[table->left_fork - 1]));
	}
	pthread_mutex_lock(table->monitor->flag_mutex);
	if (table->monitor->dead_flag)
	{
		pthread_mutex_unlock(table->monitor->flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(table->monitor->flag_mutex);
	time = calc_time(table, table->time);
	print_message("is has taken a fork", table->philo_num, time);
	return (0);
}

int	eating(t_table *table)
{
	int	time;

	pthread_mutex_lock(table->monitor->flag_mutex);
	if (table->monitor->dead_flag)
	{
		pthread_mutex_unlock(table->monitor->flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(table->monitor->flag_mutex);
	time = calc_time(table, table->time);
	print_message("is eating", table->philo_num, time);
	usleep(table->info.time_to_eat * 1000);
	return (0);
}

int	sleeping(t_table *table)
{
	int	time;

	pthread_mutex_lock(table->monitor->flag_mutex);
	if (table->monitor->dead_flag)
	{
		pthread_mutex_unlock(table->monitor->flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(table->monitor->flag_mutex);
	time = calc_time(table, table->time);
	print_message("is sleeping", table->philo_num, time);
	usleep(table->info.time_to_sleep * 1000);
	return (0);
}

int	thinking(t_table *table)
{
	int	time;

	pthread_mutex_lock(table->monitor->flag_mutex);
	if (table->monitor->dead_flag)
	{
		pthread_mutex_unlock(table->monitor->flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(table->monitor->flag_mutex);
	time = calc_time(table, table->time);
	print_message("is thinking", table->philo_num, time);
	return (0);
}
