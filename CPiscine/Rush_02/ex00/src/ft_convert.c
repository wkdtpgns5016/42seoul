/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihopark <jihopark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:37:16 by jihopark          #+#    #+#             */
/*   Updated: 2022/01/23 20:37:32 by jihopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_dict.h"

char	*ft_convert(unsigned int i, t_dict *dict)
{
	unsigned int	j;
	unsigned int	size;

	size = dict->size;
	j = 0;
	while (j < size)
	{
		if (dict->num == i)
			return (dict->eng);
		dict++;
		j++;
	}
	return (0);
}
