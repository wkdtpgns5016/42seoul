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

	size = get_size_stack(a);
	while (get_size_stack(a) != 3)
	{
		while (get_top_stack(a) != 1 && get_top_stack(a) != size)
		{
			if (get_index_stack(a, 1) == get_size_stack(a) - 1 || \
			get_index_stack(a, size) == get_size_stack(a) - 1)
				rra_stack(a);
			else if (get_index_stack(a, 1) == 1 || \
			get_index_stack(a, size) == 1)
				sa_stack(a);
			else
				ra_stack(a);
		}
		pb_stack(a, b);
	}
	push_swap_three(a);
	if (get_top_stack(b) == 5)
		sb_stack(b);
	while (get_size_stack(b) != 0)
		pa_stack(a, b);
	while (get_top_stack(a) != 1)
		ra_stack(a);
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
