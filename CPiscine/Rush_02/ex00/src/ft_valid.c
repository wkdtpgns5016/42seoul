/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihopark <jihopark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:36:08 by jihopark          #+#    #+#             */
/*   Updated: 2022/01/23 19:19:19 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	check_max(char *str)
{
	char	*max;

	max = "4294967295";
	while (*max)
	{
		if (*str < *max)
			return (1);
		max++;
		str++;
	}
	if (*(--str) == '5')
		return (1);
	return (0);
}

int	is_zero(char c)
{
	if (c == '0')
		return (1);
	return (0);
}

int	pass_space_operator(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (is_operator(str[i]))
		i++;
	while (is_zero(str[i]))
		i++;
	return (i);
}

int	ft_valid(char *str)
{
	int	i;
	int	op;

	i = pass_space_operator(str);
	op = 0;
	while (is_num(str[i]))
	{
		if (op > 9)
			return (0);
		op++;
		i++;
	}
	if (str[i] != '\0' || \
			(op == 10 && !check_max(str + (i - op))))
		return (0);
	return (1);
}
