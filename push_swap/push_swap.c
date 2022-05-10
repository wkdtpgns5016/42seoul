/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:49:59 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/10 17:50:00 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <push_swap.h>

int	main(void)
{
	t_stack	*stack;
	t_list	*list;
	int		*ptr;

	stack = 0;
	for (int i=0; i<5; i++)
	{
		push(&stack, i);
	}
	list = *(stack->list);
	while (list != 0)
	{
		ptr = (int *)(list->content);
		printf("%d\n", *ptr);
	}
}
