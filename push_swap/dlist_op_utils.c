/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_op_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:41:33 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/17 20:41:34 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	get_size_dlist(t_dlist *list)
{
	t_dlist	*temp;
	int		size;

	temp = list;
	size = 0;
	while (temp != 0)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}
