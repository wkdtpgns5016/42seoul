/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 07:40:26 by sehjang           #+#    #+#             */
/*   Updated: 2022/09/30 07:40:28 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_info	set_info(int ac, char **av)
{
	t_info	info;
	int		i;
	int		num;

	i = 1;
	info.goal = -1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if (i == 1)
			info.num_of_philo = num;
		else if (i == 2)
			info.time_to_die = num;
		else if (i == 3)
			info.time_to_eat = num;
		else if (i == 4)
			info.time_to_sleep = num;
		else if (i == 5)
			info.goal = num;
		i++;
	}
	info.start_time = get_time();
	return (info);
}

pthread_mutex_t	**set_fork(int num_of_philo)
{
	pthread_mutex_t	**fork;
	int				i;

	i = 0;
	fork = \
	(pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *) * (num_of_philo));
	while (i < num_of_philo)
	{
		fork[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(fork[i], NULL);
		i++;
	}
	return (fork);
}

t_table	*set_table(pthread_mutex_t **fork)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	table->print_able = 1;
	table->dead_flag = 0;
	table->fork = fork;
	table->flag_mutex = make_mutex();
	table->print_mutex = make_mutex();
	table->start_time = get_time();
	return (table);
}
