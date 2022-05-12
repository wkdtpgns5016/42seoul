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
#include "push_swap.h"

int	main(void)
{
	
	t_stack *stack;
	int *a;
	int *b;
	int *c;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->top = 0;

	a = malloc(sizeof(int));
	b = malloc(sizeof(int));
	c = malloc(sizeof(int));
	*a = 1;
	*b = 2;
	*c = 3;
	
	push_stack(stack,a);
	push_stack(stack,b);
	push_stack(stack,c);
	pop_stack(stack);
	
	printf("hello");
	int *test = stack->top->content;
	printf("%d\n", *test);
}
