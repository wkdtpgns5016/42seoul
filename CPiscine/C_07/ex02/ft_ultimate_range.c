/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:42:35 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/24 15:23:28 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int				*arr;
	unsigned int	i;
	unsigned int	size;

	if (min >= max)
		return (0);
	size = (unsigned int)(max - min);
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == 0)
	{
		*range = 0;
		return (-1);
	}
	i = 0;
	*range = arr;
	while (i < size)
	{
		arr[i++] = min;
		min++;
	}
	return (size);
}
