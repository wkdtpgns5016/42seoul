/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihopark <jihopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:53:49 by jihopark          #+#    #+#             */
/*   Updated: 2022/01/23 21:53:49 by jihopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	num_check(int *arr, int i)
{
	if (i == 0)
	{
		if (arr[1] == 0 && arr[2] == 0 && arr[3] == 0)
			return (0);
	}
	else if (i == 1)
	{
		if (arr[2] == 0 && arr[3] == 0)
			return (0);
	}
	else if (i == 2)
	{
		if (arr[3] == 0)
			return (0);
	}
	else if (i == 3)
		return (0);
	return (1);
}

void	ft_print(int *arr, t_dict *dict)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		 if (arr[i])
		{
			ft_write3(arr[i], dict);
			if (num_check(arr, i))
				ft_putchar(" ");
			if (i != 3)
			{
				ft_putchar(ft_convert(ft_pow(1000, 3 - i), dict));
				ft_putchar(" ");
			}
		}
		i++;
	}
	if (!arr[0] && !arr[1] && !arr[2] && !arr[3])
		ft_putchar(ft_convert(0, dict));
	ft_putchar("\n");
}
