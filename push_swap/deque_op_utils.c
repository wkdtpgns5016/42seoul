/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_op_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:41:45 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/17 20:41:45 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_front_deque(t_deque *deque, t_dlist *newnode)
{
	if (deque->front == 0)
	{
		deque->front = newnode;
		deque->rear = newnode;
		return ;
	}
	deque->front->prev = newnode;
	newnode->next = deque->front;
	deque->front = newnode;
}

void	add_rear_deque(t_deque *deque, t_dlist *newnode)
{
	if (deque->rear == 0)
	{
		deque->front = newnode;
		deque->rear = newnode;
		return ;
	}
	deque->rear->next = newnode;
	newnode->prev = deque->rear;
	deque->rear = newnode;
	newnode->next = 0;
}

t_dlist	*delete_front_deque(t_deque *deque)
{
	t_dlist	*node;

	if (deque->front == 0)
		return (0);
	if (get_size_dlist(deque->front) == 1)
	{
		node = deque->front;
		deque->front = 0;
		deque->rear = 0;
		return (node);
	}
	deque->front->next->prev = 0;
	node = deque->front;
	deque->front = deque->front->next;
	node->next = 0;
	node->prev = 0;
	return (node);
}

t_dlist	*delete_rear_deque(t_deque *deque)
{
	t_dlist	*node;

	if (deque->rear == 0)
		return (0);
	if (get_size_dlist(deque->front) == 1)
	{
		node = deque->front;
		deque->front = 0;
		deque->rear = 0;
		return (node);
	}
	deque->rear->prev->next = 0;
	node = deque->rear;
	deque->rear = deque->rear->prev;
	node->next = 0;
	node->prev = 0;
	return (node);
}
