/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:39:37 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/17 20:39:38 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pass_b_test(t_stack *a, t_stack *b, int chunk, int flag)
{
	int	num;
	int	count;

	num = 0;
	count = 0;
	while (!is_empty_stack(a))
	{
		if (get_top_stack(a) <= num)
		{
			count += pb_stack(a, b, flag);
			num++;
		}
		else if (num < get_top_stack(a) && get_top_stack(a) <= num + chunk)
		{
			count += pb_stack(a, b, flag);
			count += rb_stack(b, flag);
			num++;
		}
		else if (num + chunk < get_top_stack(a))
			count += ra_stack(a, flag);
	}
	return (count);
}

int	rotate_max_test(t_stack *b, int flag)
{
	int	max;
	int	count;

	max = get_size_stack(b);
	count = 0;
	if (find_max(b, max) == 1)
	{
		while (max != get_top_stack(b))
			count += rb_stack(b, flag);
	}
	else
	{
		while (max != get_top_stack(b))
			count += rrb_stack(b, flag);
	}
	return (count);
}

int	pass_a_test(t_stack *a, t_stack *b, int flag)
{
	int	count;

	count = 0;
	while (!is_empty_stack(b))
	{
		count += rotate_max_test(b, flag);
		count += pa_stack(a, b, flag);
	}
	return (count);
}
