/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:39:53 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/17 20:39:54 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa_stack(t_stack *a, t_stack *b, int flag)
{
	t_dlist	*node;

	if (is_empty_stack(b))
		return (0);
	node = delete_front_deque(b->top);
	add_front_deque(a->top, node);
	if (flag)
		ft_putstr_fd("pa\n", 1);
	return (1);
}

int	pb_stack(t_stack *a, t_stack *b, int flag)
{
	t_dlist	*node;

	if (is_empty_stack(a))
		return (0);
	node = delete_front_deque(a->top);
	add_front_deque(b->top, node);
	if (flag)
		ft_putstr_fd("pb\n", 1);
	return (1);
}
