/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 07:40:46 by sehjang           #+#    #+#             */
/*   Updated: 2022/09/30 07:40:48 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	put_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->table->fork[philo->left_fork]);
	pthread_mutex_unlock(philo->table->fork[philo->right_fork]);
	return (0);
}

int	pick_up_fork(t_philo *philo)
{
	if (philo->info->num_of_philo == 1)
	{
		pthread_mutex_lock(philo->table->fork[philo->right_fork]);
		print_philo(philo, "is has taken a fork");
		while (check_dead(philo) != 1)
			;
	}
	else
	{
		if (philo->philo_num % 2 == 0)
		{
			pthread_mutex_lock(philo->table->fork[philo->right_fork]);
			print_philo(philo, "is has taken a fork");
			pthread_mutex_lock(philo->table->fork[philo->left_fork]);
			print_philo(philo, "is has taken a fork");
		}
		else
		{
			pthread_mutex_lock(philo->table->fork[philo->left_fork]);
			print_philo(philo, "is has taken a fork");
			pthread_mutex_lock(philo->table->fork[philo->right_fork]);
			print_philo(philo, "is has taken a fork");
		}
	}
	return (0);
}

int	eating(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(philo->table->print_mutex);
	time = get_time() - philo->info->start_time;
	if (philo->table->print_able)
		print_message("is eating", philo->philo_num + 1, time);
	pthread_mutex_lock(philo->last_eat_mutex);
	philo->last_eat_time = get_time();
	philo->eat_count++;
	pthread_mutex_unlock(philo->last_eat_mutex);
	pthread_mutex_unlock(philo->table->print_mutex);
	ft_sleep(philo->info->time_to_eat * 1000);
	return (0);
}

int	sleeping(t_philo *philo)
{
	print_philo(philo, "is sleeping");
	ft_sleep(philo->info->time_to_sleep * 1000);
	return (0);
}

int	thinking(t_philo *philo)
{
	print_philo(philo, "is thinking");
	return (0);
}
