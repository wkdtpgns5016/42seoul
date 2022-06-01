/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:49:59 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/10 17:50:00 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test(int args, char **argc, int chunk)
{
	t_stack	*a;
	t_stack	*b;
	int		count;

	a = make_a_stack(args, argc);
	b = (t_stack *)malloc(sizeof(t_stack));
	count = 0;
	if (a == 0 || b == 0)
	{
		free_ab_stack(a, b);
		error_message();
	}
	init_stack(b);
	count += pass_b_test(a, b, chunk, 0);
	count += pass_a_test(a, b, 0);
	free_ab_stack(a, b);
	return (count);
}

void	start_hour_glass(t_stack *a, t_stack *b, int args, char **argc)
{
	int	chunk;
	int	size;
	int	count;

	size = get_size_stack(a);
	chunk = get_chunk((double)size);
	count = test(args, argc, chunk);
	if (count > 7000)
		pass_b(a, b, chunk, 2);
	else
		pass_b(a, b, chunk, 1);
	pass_a(a, b, 1);
}

void	push_swap(t_stack *a, t_stack *b, int args, char **argc)
{
	int	size;

	size = get_size_stack(a);
	if (size <= 5)
	{
		push_swap_small(a, b, size);
		return ;
	}
	if (is_descending_order_stack(a))
	{
		while (get_size_stack(a) != 0)
			pb_stack(a, b, 1);
		while (get_size_stack(b) != 0)
		{
			pa_stack(a, b, 1);
			ra_stack(a, 1);
		}
		return ;
	}
	start_hour_glass(a, b, args, argc);
}
