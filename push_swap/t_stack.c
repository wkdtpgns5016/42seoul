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

#include <push_swap.h>
#include <stdio.h>

t_stack	*stack_new(int num)
{
	t_stack	*stack;
	t_list	*node;

	stack = (t_stack *)malloc(sizeof(t_stack));
	node = ft_lstnew(&num);
	stack->list = &node;
	if (stack->list == 0)
		return (0);
	stack->top = ft_lstlast(*(stack->list));
	return (stack);
}

void	free_content(void *content)
{
	if (content != 0)
		free(content);
	content = 0;
}

void	stack_clear(t_stack **stack, void (*del)(void *))
{
	ft_lstclear((*stack)->list, del);
	(*stack)->top = 0;
	free(*stack);
	*stack = 0;
}

void	push(t_stack **stack, int num)
{
	t_list	*new;
	t_stack	*temp;
	void	(*del)(void *);
	int		*ptr;

	temp = *stack;
	del = free_content;
	if (temp == 0)
		temp = stack_new(num);
	else
	{
		new = ft_lstnew(&num);
		if (new == 0)
		{
			stack_clear(stack, del);
			return ;
		}
		ft_lstadd_back(temp->list, new);
		temp->top = ft_lstlast(*(temp->list));
	}
}
