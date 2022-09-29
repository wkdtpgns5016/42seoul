/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 07:40:51 by sehjang           #+#    #+#             */
/*   Updated: 2022/09/30 07:40:52 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->table->flag_mutex);
	if (philo->table->dead_flag)
	{
		pthread_mutex_unlock(philo->table->flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->table->flag_mutex);
	return (0);
}

void	dead(t_philo *philo, uint64_t time)
{
	print_message("is dead", philo->philo_num + 1, time);
}
