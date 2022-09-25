/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:56:24 by sehjang           #+#    #+#             */
/*   Updated: 2022/07/12 15:56:25 by sehjang          ###   ########.fr       */
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
		if (i == 1 && num < 2)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_table		table;
	t_monitor	monitor;
	pthread_t	**philos;
	int			i;

	if (check_arg(ac, av))
	{
		printf("Arguments Error\n");
		return (0);
	}
	table = set_table(ac, av);
	philos = set_philo(table);
	monitor = set_monitor(philos);
	monitor.time = (int *)malloc(sizeof(int) * table.info.num_of_philo);
	i = 0;
	while (i < table.info.num_of_philo)
		monitor.time[i++] = 0;
	table.monitor = &monitor;
	create_philos(philos, table);
	i = 0;
	while (i < table.info.num_of_philo)
	{
		pthread_join(*philos[i], NULL);
		i++;
	}
	return (0);
}
