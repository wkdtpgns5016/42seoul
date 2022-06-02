/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vaild_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:41:54 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/17 20:41:56 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_vaild_num(char *str)
{
	int	result;

	result = 0;
	while (*str == '\t' || *str == '\r' || *str == '\v' || \
			*str == '\n' || *str == ' ' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str == '\0')
		result = 1;
	return (result);
}

static int	is_intager_arg(int args, char **argc)
{
	int			i;
	long long	num;

	i = 0;
	while (i < args)
	{
		if (!is_vaild_num(argc[i]))
			return (0);
		num = ft_atol(argc[i]);
		if (num > 2147483647 || num < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

static int	is_duplicate_arg(int args, int *argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < args - 1)
	{
		j = i + 1;
		while (j < args)
		{
			if (i != j)
			{
				if (argc[i] == argc[j])
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	error_message(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	*check_vaild_arg(int size, char **arr, int flag)
{
	int	*new_arr;

	if (!is_intager_arg(size, arr))
	{
		if (flag)
			free_strs(arr);
		error_message();
	}
	new_arr = 0;
	new_arr = convert_int_arg(size, arr);
	if (new_arr == 0)
		return (0);
	if (is_duplicate_arg(size, new_arr))
	{
		if (flag)
			free_strs(arr);
		ft_free(new_arr);
		error_message();
	}
	if (flag)
		free_strs(arr);
	return (new_arr);
}
