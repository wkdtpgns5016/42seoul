/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 07:40:35 by sehjang           #+#    #+#             */
/*   Updated: 2022/09/30 07:40:35 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	*action(void *data)
{
	t_philo			*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(philo->last_eat_mutex);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(philo->last_eat_mutex);
	if (philo->philo_num % 2 != 0)
		ft_sleep((philo->info->time_to_eat / 2) * 1000);
	while (check_dead(philo) == 0)
	{
		pick_up_fork(philo);
		eating(philo);
		put_down_fork(philo);
		sleeping(philo);
		thinking(philo);
		usleep(500);
	}
	return (0);
}

void	create_philo_thread(t_monitor monitor, t_info info)
{
	t_philo	**philos;
	int		total;
	int		i;

	philos = monitor.philos;
	total = info.num_of_philo;
	i = 0;
	while (i < total)
	{
		pthread_create(philos[i]->philo, NULL, action, (void *)philos[i]);
		i++;
	}
}

t_philo	*set_philo(int num, t_info *info, t_table *table)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->philo_num = num;
	philo->left_fork = get_left_fork(num, info->num_of_philo);
	philo->right_fork = get_right_fork(num);
	philo->philo = (pthread_t *)malloc(sizeof(pthread_t));
	philo->last_eat_mutex = make_mutex();
	philo->info = info;
	philo->eat_count = 0;
	philo->goal_flag = 0;
	philo->table = table;
	return (philo);
}
