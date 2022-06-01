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

int	rra_stack(t_stack *a, int flag)
{
	reverse_rotate_stack(a);
	if (flag)
		ft_putstr_fd("rra\n", 1);
	return (1);
}

int	rrb_stack(t_stack *b, int flag)
{
	reverse_rotate_stack(b);
	if (flag)
		ft_putstr_fd("rrb\n", 1);
	return (1);
}

int	rrr_stack(t_stack *a, t_stack *b, int flag)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	if (flag)
		ft_putstr_fd("rrr\n", 1);
	return (1);
}
