#include "../include/philo.h"

void	dead(t_table *table)
{
	int	time;

	time = calc_time(table, table->time);
	print_message("is dead", table->philo_num, time);
	table->monitor->dead_flag = 1;
}
