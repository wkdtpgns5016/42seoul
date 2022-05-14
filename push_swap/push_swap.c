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
	if (front > mid && front > rear && mid > rear)
		return (2);
	if (front > mid && front > rear && mid < rear)
		return (3);
	if (front < mid && front < rear && mid > rear)
		return (4);
	if (front < mid && front > rear && mid > rear)
		return (5);
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
	/*code*/
}

void	push_swap_small(t_stack *a, t_stack *b, int size)
{
	if (size < 3)
		sa_stack(a);
	else if (size == 3)
		push_swap_three(a, b);
	else if (size > 3)
		push_swap_over(a, b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	num;
	int	chunk;
	int	size;

	num = 0;
	size = get_size_stack(a);
	if (size <= 5)
	{
		push_swap_small(a, b, size);
		return ;
	}
	chunk = get_chunk((double)size);
	pass_b(a, b, num, chunk);
	pass_a(a, b);
}
