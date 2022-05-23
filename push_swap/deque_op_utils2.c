/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_op_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:41:45 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/17 20:41:45 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_deque(t_deque	*deque)
{
	deque->front = 0;
	deque->rear = 0;
}

int	get_size_deque(t_deque *deque)
{
	return (get_size_dlist(deque->front));
}

void	clear_deque(t_deque *deque)
{
	t_dlist	*ptr;

	while (get_size_deque(deque) != 0)
	{
		ptr = delete_front_deque(deque);
		free(ptr->data);
		free(ptr);
	}
}
