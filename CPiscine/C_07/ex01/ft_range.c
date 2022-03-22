/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:36:15 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/24 15:20:45 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*arr;
	unsigned int	i;
	unsigned int	size;

	if (min >= max)
		return (0);
	size = (unsigned int)(max - min);
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		arr[i++] = min;
		min++;
	}
	return (arr);
}
