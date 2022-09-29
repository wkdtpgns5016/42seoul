/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 07:40:05 by sehjang           #+#    #+#             */
/*   Updated: 2022/09/30 07:40:07 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_exit(t_table *table)
{
	table->print_able = 0;
	pthread_mutex_lock(table->flag_mutex);
	table->dead_flag = 1;
	pthread_mutex_unlock(table->flag_mutex);
}

int	check_clear(t_philo **philos, t_info *info)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < info->num_of_philo)
	{
		if (info->goal < 0)
			break ;
		if (philos[i]->eat_count >= info->goal)
			count++;
		i++;
	}
	if (count == info->num_of_philo)
		return (1);
	return (0);
}

int	check_philo_state(t_philo **philos, t_info *info, int i)
{
	uint64_t	time;

	pthread_mutex_lock(philos[i]->table->print_mutex);
	pthread_mutex_lock(philos[i]->last_eat_mutex);
	time = get_time() - philos[i]->last_eat_time;
	if (time > (uint64_t)(info->time_to_die * 1000))
	{
		dead(philos[i], time);
		set_exit(philos[i]->table);
		pthread_mutex_unlock(philos[i]->last_eat_mutex);
		pthread_mutex_unlock(philos[i]->table->print_mutex);
		return (1);
	}
	else
	{
		if (check_clear(philos, info))
		{
			set_exit(philos[i]->table);
			pthread_mutex_unlock(philos[i]->last_eat_mutex);
			pthread_mutex_unlock(philos[i]->table->print_mutex);
			return (1);
		}
	}
	return (0);
}

void	*monitor_philo(void *data)
{
	int			i;
	t_monitor	*monitor;
	t_philo		**philos;
	t_info		*info;

	monitor = (t_monitor *)data;
	philos = monitor->philos;
	info = monitor->philos[0]->info;
	while (check_dead(philos[0]) == 0)
	{
		i = 0;
		while (i < info->num_of_philo)
		{
			if (check_philo_state(philos, info, i))
				break ;
			pthread_mutex_unlock(philos[i]->last_eat_mutex);
			pthread_mutex_unlock(philos[i]->table->print_mutex);
			i++;
		}
	}
	return (0);
}

t_monitor	set_monitor(t_info *info, t_table *table)
{
	t_monitor		monitor;
	int				i;

	monitor.monitor = (pthread_t *)malloc(sizeof(pthread_t));
	monitor.philos = (t_philo **)malloc(sizeof(t_philo *) * info->num_of_philo);
	i = 0;
	while (i < info->num_of_philo)
	{
		monitor.philos[i] = set_philo(i, info, table);
		i++;
	}
	return (monitor);
}
