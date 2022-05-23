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
	clear_stack(a);
	clear_stack(b);
	ft_free(a);
	ft_free(b);
}

int	main(int args, char **argc)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	char	**arr;

	size = args - 1;
	arr = argc + 1;
	if (args <= 1)
		error_message();
	else if (args == 2)
	{
		size = 0;
		arr = ft_split(argc[1], ' ');
		while (arr[size] != 0)
			size++;
	}
	check_vaild_arg(size, arr);
	a = parsing_arg(size, arr);
	b = (t_stack *)malloc(sizeof(t_stack));
	if (a == 0 || b == 0)
		error_message();
	init_stack(b);
	if (!is_ascending_order_stack(a))
		push_swap(a, b);
	free_ab_stack(a, b);
}
