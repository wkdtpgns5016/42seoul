
#include "../include/philo.h"

int	get_left_fork(int philo_num, int total_philo)
{
	if (philo_num == 0)
		return (total_philo - 1);
	else
		return (philo_num - 1);
}

int	get_right_fork(int philo_num)
{
	return (philo_num);
}

uint64_t	calc_ms(struct timeval time)
{
	uint64_t		ms;
	struct timeval	end;

	gettimeofday(&end, NULL);
	ms = (end.tv_sec - time.tv_sec) * 1000 * 1000;
	ms += (end.tv_usec - time.tv_usec);
	return (ms);
}

uint64_t	get_time(void)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return (end.tv_sec * 1000000 + end.tv_usec);
}
