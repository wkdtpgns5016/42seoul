/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:45:16 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/26 17:45:17 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_stack(t_stack *stack, int value)
{
	t_dlist	*list;
	int		index;

	list = stack->top->front;
	index = 0;
	while (list != 0)
	{
		if (value == *(int *)(list->data))
			return (index);
		index++;
		list = list->next;
	}
	return (-1);
}

int	is_ascending_order_stack(t_stack *stack)
{
	int		max;
	t_dlist	*list;

	max = -1;
	list = stack->top->front;
	while (list != 0)
	{
		if (max < *(int *)(list->data))
			max = *(int *)(list->data);
		else
			return (0);
		list = list->next;
	}
	return (1);
}

int	is_descending_order_stack(t_stack *stack)
{
	int		min;
	t_dlist	*list;

	min = 2147483647;
	list = stack->top->front;
	while (list != 0)
	{
		if (min > *(int *)(list->data))
			min = *(int *)(list->data);
		else
			return (0);
		list = list->next;
	}
	return (1);
}

void	clear_stack(t_stack *stack)
{
	clear_deque(stack->top);
	ft_free(stack->top);
}
