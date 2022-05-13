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

int	is_empty_stack(t_stack *stack)
{
	if (stack->top == 0)
		return (1);
	else return (0);
}

void	push_stack(t_stack *stack, void *data)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	newnode->content = data;
	newnode->next = stack->top;
	stack->top = newnode;
}

void	*pop_stack(t_stack *stack)
{
	t_list	*node;
	void	*data;

	if (is_empty_stack(stack))
		return (0);
	node = stack->top;
	data = node->content;
	stack->top = node->next;
	free(node);
	return (data);
}
