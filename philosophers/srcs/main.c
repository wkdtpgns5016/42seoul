/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:56:24 by sehjang           #+#    #+#             */
/*   Updated: 2022/09/30 07:39:20 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_arg(int ac, char **av)
{
	int	i;
	int	num;

	i = 1;
	if (!(ac == 5 || ac == 6))
		return (1);
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if (num <= 0)
			return (1);
		if (i == 1 && num < 1)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_monitor		monitor;
	pthread_mutex_t	**fork;
	t_info			info;
	t_table			*table;
	int				i;

	if (check_arg(ac, av))
	{
		printf("Error\n");
		exit(1);
	}
	info = set_info(ac, av);
	fork = set_fork(info.num_of_philo);
	table = set_table(fork);
	monitor = set_monitor(&info, table);
	create_philo_thread(monitor, info);
	pthread_create(monitor.monitor, NULL, monitor_philo, (void *)&monitor);
	i = 0;
	while (i < info.num_of_philo)
	{
		pthread_join(*monitor.philos[i]->philo, NULL);
		i++;
	}
	pthread_join(*monitor.monitor, NULL);
}
