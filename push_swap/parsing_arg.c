/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:54:33 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/10 18:54:35 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*convert_int_arg(int args, char **argc)
{
	int	*arr;
	int	i;
	int	j;

	arr = (int *)malloc(sizeof(int) * args - 1);
	if (arr == 0)
		return (0);
	i = 1;
	j = 0;
	while (i < args)
	{
		arr[j] = ft_atoi(argc[i]);
		i++;
		j++;
	}
	return (arr);
}

static int	*rank_arr(int *arr, int args)
{
	int	i;
	int	j;
	int	rank;
	int	*new_arr;

	new_arr = (int *)malloc(sizeof(int) * args - 1);
	if (new_arr == 0 || arr == 0)
		return (0);
	i = 0;
	while (i < args - 1)
	{
		j = 0;
		rank = 0;
		while (j < args - 1)
		{
			if (arr[i] > arr[j])
				rank++;
			j++;
		}
		new_arr[i] = rank;
		i++;
	}
	return (new_arr);
}

static int	*make_arr(int args, char **argc)
{
	int	*temp;
	int	*arr;

	temp = convert_int_arg(args, argc);
	arr = rank_arr(temp, args);
	if (temp != 0)
	{
		free(temp);
		temp = 0;
	}
	return (arr);
}

t_deque	*make_deque(int args, char **argc)
{
	t_deque	*deque;
	int		i;
	int		*arr;
	int		*data;
	
	deque = (t_deque *)malloc(sizeof(t_deque));
	if (deque == 0)
		return (0);
	init_deque(deque);
	arr = make_arr(args, argc);
	i = 0;
	while (i < args - 1)
	{
		data = (int *)malloc(sizeof(int));
		*data = arr[i];
		add_rear_deque(deque, data);
		i++;
	}
	free(arr);
	arr = 0;
	return (deque);
}

t_stack	*parsing_arg(int args, char **argc)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->top = make_deque(args, argc);
	return (stack);
}
