/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:40:04 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/17 20:40:04 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_stack *a)
{
	t_dlist	*node;

	if (get_size_stack(a) < 2)
		return ;
	node = delete_rear_deque(a->top);
	add_front_deque(a->top, node);
}

void	rra_stack(t_stack *a)
{
	reverse_rotate_stack(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb_stack(t_stack *b)
{
	reverse_rotate_stack(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr_stack(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	ft_putstr_fd("rrr\n", 1);
}
