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

int	get_chunk(double x)
{
	double	y;

	y = 0.000000053 * x * x + 0.03 * x + 14.5;
	return ((int)y);
}

void	pass_b(t_stack *a, t_stack *b, int chunk, int flag)
{
	int	num;

	num = 0;
	while (!is_empty_stack(a))
	{
		if (get_top_stack(a) <= num)
		{
			pb_stack(a, b, flag);
			num++;
		}
		else if (num < get_top_stack(a) && get_top_stack(a) <= num + chunk)
		{
			pb_stack(a, b, flag);
			rb_stack(b, flag);
			num++;
		}
		else if (num + chunk < get_top_stack(a))
		{
			if (flag == 2)
				rra_stack(a, flag);
			else
				ra_stack(a, flag);
		}
	}
}

int	find_max(t_stack *stack, int max)
{
	t_dlist	*temp;
	int		size;
	int		i;
	int		data;

	temp = stack->top->front;
	size = get_size_dlist(temp);
	i = 0;
	while (temp != 0)
	{
		data = *(int *)(temp->data);
		if (max == data)
			return (1);
		temp = temp ->next;
		i++;
		if (i > size / 2)
			break ;
	}
	return (0);
}

void	rotate_max(t_stack *b, int flag)
{
	int	max;

	max = get_size_stack(b);
	if (find_max(b, max) == 1)
	{
		while (max != get_top_stack(b))
			rb_stack(b, flag);
	}
	else
	{
		while (max != get_top_stack(b))
			rrb_stack(b, flag);
	}
}

void	pass_a(t_stack *a, t_stack *b, int flag)
{
	while (!is_empty_stack(b))
	{
		rotate_max(b, flag);
		pa_stack(a, b, flag);
	}
}
