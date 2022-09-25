
#include "../include/philo.h"

int	get_left_fork(int philo_num, int total_philo)
{
	if (philo_num == 1)
		return (total_philo);
	else
		return (philo_num - 1);
}

int	get_right_fork(int philo_num)
{
	return (philo_num);
}

int	calc_time(t_table *table, struct timeval start)
{
	int				time;
	struct timeval	end;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(table->time_mutex);
	time = (end.tv_sec - start.tv_sec) * 1000;
	time += ((end.tv_usec - start.tv_usec) / 1000);
	pthread_mutex_unlock(table->time_mutex);
	return (time);
}

int	check_dead(t_table *table, int start, int end)
{
	if (end - start > table->info.time_to_die)
		return (1);
	return (0);
}
