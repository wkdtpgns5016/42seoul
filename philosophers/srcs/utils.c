/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 07:41:03 by sehjang           #+#    #+#             */
/*   Updated: 2022/09/30 07:41:04 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(const char *nptr)
{
	int	mark;
	int	num;

	mark = 1;
	num = 0;
	while (*nptr == '\t' || *nptr == '\r' || *nptr == '\v' || \
			*nptr == '\n' || *nptr == ' ' || *nptr == '\f')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			mark *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = (num * 10) + (*nptr - '0');
		nptr++;
	}
	return (mark * num);
}

void	print_message(char *str, int philo_num, uint64_t time)
{
	printf("%lld %d %s\n", (time / 1000), philo_num, str);
}

uint64_t	get_time(void)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return (end.tv_sec * 1000000 + end.tv_usec);
}

void	ft_sleep(int us)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < (uint64_t)(us))
	{
		usleep(100);
	}
}

pthread_mutex_t	*make_mutex(void)
{
	pthread_mutex_t	*mutex;

	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex, NULL);
	return (mutex);
}
