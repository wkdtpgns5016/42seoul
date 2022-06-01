/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:39:18 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/17 20:39:19 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_ab_stack(t_stack *a, t_stack *b)
{
	if (a != 0)
	{
		clear_stack(a);
		ft_free(a);
	}
	if (b != 0)
	{
		clear_stack(b);
		ft_free(b);
	}
}

t_stack	*make_a_stack(int args, char **argc)
{
	t_stack	*a;
	int		size;
	char	**arr;
	int		flag;

	size = args - 1;
	arr = argc + 1;
	a = 0;
	flag = 0;
	if (args <= 1)
		error_message();
	else if (args == 2)
	{
		size = 0;
		arr = ft_split(argc[1], ' ');
		while (arr[size] != 0)
			size++;
		flag = 1;
	}
	a = parsing_arg(size, arr, flag);
	return (a);
}

int	main(int args, char **argc)
{
	t_stack	*a;
	t_stack	*b;

	a = make_a_stack(args, argc);
	b = (t_stack *)malloc(sizeof(t_stack));
	if (a == 0 || b == 0)
	{
		free_ab_stack(a, b);
		error_message();
	}
	init_stack(b);
	if (!is_ascending_order_stack(a))
		push_swap(a, b, args, argc);
	free_ab_stack(a, b);
}
