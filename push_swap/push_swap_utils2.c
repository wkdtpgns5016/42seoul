/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:02:11 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/19 20:02:12 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	get_case_three_stack(t_stack *a)
{
	int	front;
	int	rear;
	int	mid;

	front = *(int *)(a->top->front->data);
	rear = *(int *)(a->top->rear->data);
	mid = *(int *)(a->top->front->next->data);
	if (front > mid && front < rear && mid < rear)
		return (1);
	else if (front > mid && front > rear && mid > rear)
		return (2);
	else if (front > mid && front > rear && mid < rear)
		return (3);
	else if (front < mid && front < rear && mid > rear)
		return (4);
	else if (front < mid && front > rear && mid > rear)
		return (5);
	return (-1);
}

void	push_swap_three(t_stack *a)
{
	int	flag;

	flag = get_case_three_stack(a);
	if (flag == 1)
		sa_stack(a);
	else if (flag == 2)
	{
		sa_stack(a);
		rra_stack(a);
	}
	else if (flag == 3)
		ra_stack(a);
	else if (flag == 4)
	{
		sa_stack(a);
		ra_stack(a);
	}
	else if (flag == 5)
		rra_stack(a);
}

void	push_swap_over(t_stack *a, t_stack *b)
{
	int	size;
	int	top;

	size = get_size_stack(a);
	while (get_size_stack(a) != 3)
		pb_stack(a, b);
	push_swap_three(a);
	print_stack(a);
	print_stack(b);
	while (get_size_stack(b) != 0)
	{

		getchar();
		top = get_top_stack(b);
		while (get_top_stack(a) != top + 1)
			ra_stack(a);
		if (top == size)
		{
			pa_stack(a, b);
			ra_stack(a);
		}
		else
			pa_stack(a, b);
		getchar();
	}
}

void	push_swap_small(t_stack *a, t_stack *b, int size)
{
	if (size < 3)
		sa_stack(a);
	else if (size == 3)
		push_swap_three(a);
	else if (size > 3)
		push_swap_over(a, b);
}
