/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:40:57 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/17 20:41:03 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atol(const char *nptr)
{
	long long	mark;
	long long	num;

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
