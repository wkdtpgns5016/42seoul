/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:45:50 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/26 17:45:50 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert_int_arg(int args, char **argc)
{
	int	*arr;
	int	i;
	int	j;

	arr = (int *)malloc(sizeof(int) * args - 1);
	if (arr == 0)
		return (0);
	i = 0;
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

	new_arr = (int *)malloc(sizeof(int) * args);
	if (new_arr == 0 || arr == 0)
		return (0);
	i = 0;
	while (i < args)
	{
		j = 0;
		rank = 1;
		while (j < args)
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

static int	*make_arr(int args, int *argc)
{
	int	*arr;

	arr = rank_arr(argc, args);
	if (argc != 0)
		ft_free(argc);
	return (arr);
}

static void	add_value_deque(t_deque *deque, int args, int *arr)
{
	int		i;
	int		*data;
	t_dlist	*newnode;

	i = 0;
	while (i < args)
	{
		data = (int *)malloc(sizeof(int));
		newnode = (t_dlist *)malloc(sizeof(t_dlist));
		if (data == 0 || newnode == 0)
		{
			clear_deque(deque);
			ft_free(deque);
			return ;
		}
		*data = arr[i];
		newnode->data = data;
		newnode->next = 0;
		newnode->prev = 0;
		add_rear_deque(deque, newnode);
		i++;
	}
}

t_deque	*make_deque(int args, int *argc)
{
	t_deque	*deque;
	int		*arr;

	deque = (t_deque *)malloc(sizeof(t_deque));
	if (deque == 0)
		return (0);
	init_deque(deque);
	arr = make_arr(args, argc);
	if (arr == 0)
	{
		ft_free(deque);
		return (0);
	}
	add_value_deque(deque, args, arr);
	if (arr != 0)
		ft_free(arr);
	return (deque);
}
