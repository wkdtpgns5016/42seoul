/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:40:23 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/17 20:40:24 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *a)
{
	t_dlist	*top;
	t_dlist	*prev;

	if (get_size_stack(a) < 2)
		return ;
	top = delete_front_deque(a->top);
	prev = delete_front_deque(a->top);
	add_front_deque(a->top, top);
	add_front_deque(a->top, prev);
}

void	sa_stack(t_stack *a)
{
	swap_stack(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb_stack(t_stack *b)
{
	swap_stack(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss_stack(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	ft_putstr_fd("ss\n", 1);
}
