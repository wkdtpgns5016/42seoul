/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihopark <jihopark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:23:45 by jihopark          #+#    #+#             */
/*   Updated: 2022/01/23 21:23:56 by jihopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	print_value(int mod, t_dict *dict, int *num)
{
	if (mod == 0)
	{
		ft_putchar(ft_convert(num[0], dict));
		ft_putchar(" ");
		ft_putchar(ft_convert(100, dict));
	}
	else if (mod == 1)
	{
		ft_putchar(ft_convert(num[1], dict));
	}
	else
	{
		if (num[2] == 0)
			ft_putchar(ft_convert(num[3], dict));
		else
		{
			ft_putchar(ft_convert(num[3], dict));
			ft_putchar(" ");
			ft_putchar(ft_convert(num[2], dict));
		}
	}
}

void	ft_write3(int i, t_dict *dict)
{
	int	num[4];

	num[0] = i / 100;
	num[1] = i % 100;
	num[2] = num[1] % 10;
	num[3] = num[1] - num[2];
	if (num[0] != 0)
	{
		print_value(0, dict, num);
		if (num[1] != 0)
			ft_putchar(" ");
	}
	if (num[1] > 0 && num[1] < 20)
		print_value(1, dict, num);
	if (num[1] >= 20 && num[1] < 100)
		print_value(2, dict, num);
}
