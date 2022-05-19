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

void	push_swap(t_stack *a, t_stack *b)
{
	int	num;
	int	chunk;
	int	size;

	num = 0;
	size = get_size_stack(a);
	if (is_descending_order_stack(a))
	{
		while (get_top_stack(a) != 0)
			ra_stack(a);
		return ;
	}
	else
	{
		if (size <= 5)
		{
			push_swap_small(a, b, size);
			return ;
		}
		chunk = get_chunk((double)size);
		pass_b(a, b, num, chunk);
		pass_a(a, b);
	}
}
