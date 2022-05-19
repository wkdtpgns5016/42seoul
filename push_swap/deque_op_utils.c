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
#include "libft/libft.h"

void	init_deque(t_deque	*deque)
{
	deque->front = 0;
	deque->rear = 0;
}

int	get_size_deque(t_deque *deque)
{
	return (get_size_dlist(deque->front));
}

void	add_front_deque(t_deque *deque, void *data)
{
	t_dlist	*newnode;

	newnode = (t_dlist *)malloc(sizeof(t_dlist));
	newnode->data = data;
	newnode->next = 0;
	newnode->prev = 0;
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

void	add_rear_deque(t_deque *deque, void *data)
{
	t_dlist	*newnode;

	newnode = (t_dlist *)malloc(sizeof(t_dlist));
	newnode->data = data;
	if (deque->rear == 0)
	{
		newnode->next = 0;
		newnode->prev = 0;
		deque->front = newnode;
		deque->rear = newnode;
		return ;
	}
	deque->rear->next = newnode;
	newnode->prev = deque->rear;
	deque->rear = newnode;
	newnode->next = 0;
}

void	*delete_front_deque(t_deque *deque)
{
	void	*data;
	t_dlist	*node;

	if (deque->front == 0)
		return (0);
	data = deque->front->data;
	if (get_size_dlist(deque->front) == 1)
	{
		node = deque->front;
		deque->front = 0;
		deque->rear = 0;
		free(node);
		return (data);
	}
	deque->front->next->prev = 0;
	node = deque->front;
	deque->front = deque->front->next;
	free(node);
	return (data);
}

void	*delete_rear_deque(t_deque *deque)
{
	void	*data;
	t_dlist	*node;

	if (deque->rear == 0)
		return (0);
	data = deque->rear->data;
	if (get_size_dlist(deque->front) == 1)
	{
		node = deque->front;
		deque->front = 0;
		deque->rear = 0;
		free(node);
		return (data);
	}
	deque->rear->prev->next = 0;
	node = deque->rear;
	deque->rear = deque->rear->prev;
	free(node);
	return (data);
}
