/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:39:37 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/17 20:39:38 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pass_b(t_stack *a, t_stack *b, int count)
{
	int	pivot[2];
	int	size;
	int	ra;
	int	pa;
	int	rb;

	size = get_size_stack(b);
	if (count == 1)
	{
		pa_stack(a, b);
		return ;
	}
	pivot[0] = size / 3;
	pivot[1] = (size / 3) * 2;
	while (count-- > 0)
	{
		if (get_top_stack(b) < pivot[0])
		{
			rb_stack(b);
			rb++;
		}
		else
		{
			pa_stack(a, b);
			pa++;
			if (get_top_stack(b) < pivot[1])
			{
				ra_stack(a);
				ra++;
			}
		}
	}
	pass_a(a, b, pa - ra);
	while (rb-- > 0)
		rrb_stack(b);
	pass_a(a, b, pa);
	pass_b(a, b, rb);
}

void	pass_a(t_stack *a, t_stack *b, int count)
{
	int	pivot[2];
	int	size;
	int	ra;
	int	pb;
	int	rb;

	size = get_size_stack(a);
	if (count < 3)
	{
		if (count == 2)
		{
			if (!is_ascending_order_stack(a))
				sa_stack(a);
		}
		return ;
	}
	pivot[0] = size / 3;
	pivot[1] = (size / 3) * 2;
	while (count-- > 0)
	{
		if (get_top_stack(a) >= pivot[1])
		{
			ra_stack(a);
			ra++;
		}
		else
		{
			pb_stack(a, b);
			pb++;
			if (get_top_stack(b) >= pivot[0])
			{
				rb_stack(b);
				rb++;
			}
		}
	}
	while (ra-- > 0)
		rra_stack(a);
	pass_a(a, b, ra);
	pass_b(a, b, pb);
}
