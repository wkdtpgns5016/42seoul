/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:45:36 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/26 17:45:37 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(void *ptr)
{
	if (ptr != 0)
	{
		free(ptr);
		ptr = 0;
	}
}

void	free_strs(char **argc)
{
	int	i;

	i = 0;
	while (argc[i] != 0)
	{
		ft_free(argc[i]);
		i++;
	}
	ft_free(argc);
}
