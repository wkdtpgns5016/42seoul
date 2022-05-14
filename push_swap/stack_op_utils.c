/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:54:21 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/10 18:54:22 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = (t_deque *)malloc(sizeof(t_deque));
	init_deque(stack->top);
}

int	is_empty_stack(t_stack *stack)
{
	if (stack->top->front == 0)
		return (1);
	else return (0);
}

int	get_size_stack(t_stack *stack)
{
	return (get_size_deque(stack->top));
}

void	print_stack(t_stack *b)
{
	t_dlist *list = b->top->front;
	while (list != 0)
	{
		ft_putnbr_fd(*(int *)(list->data), 1);
		ft_putstr_fd(" ", 1);
		list = list->next;
	}
	ft_putstr_fd("\n", 1);
}

int	get_top_stack(t_stack *stack)
{
	return (*(int *)(stack->top->front->data));
}
