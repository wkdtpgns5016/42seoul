/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:29:55 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/11 10:46:24 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_number_level(int	nb)
{
	int	count;

	count = 0;
	while (nb > 0)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}

int	get_square_number(int	level)
{
	int	unit;

	unit = 1;
	while (level-- > 1)
		unit = unit * 10;
	return (unit);
}

void	print_number(int	nb, int	unit)
{
	char	num;
	int		head;

	while (unit > 0)
	{
		head = nb / unit;
		num = head + '0';
		write(1, &num, 1);
		nb = nb % unit;
		unit = unit / 10;
	}
}

void	ft_putnbr(int	nb)
{
	int	level;
	int	unit;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 0)
		write(1, "0", 1);
	else
	{
		if (nb < 0)
		{
			nb = nb * -1;
			write(1, "-", 1);
		}
		level = get_number_level(nb);
		unit = get_square_number(level);
		print_number(nb, unit);
	}
}
