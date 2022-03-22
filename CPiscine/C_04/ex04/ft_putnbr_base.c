/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:58:31 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/18 15:58:47 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (*str++ != '\0')
		i++;
	return (i);
}

int	check_duplicate(char *base, unsigned int base_size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < base_size)
	{
		j = 0;
		while (j < base_size)
		{
			if (j != i && base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_mark(char *base, unsigned int base_size)
{
	unsigned int	i;

	i = 0;
	while (i < base_size)
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

void	change_base(unsigned int nbr, int base_size, char *base)
{
	unsigned int	div;
	unsigned int	mod;

	if (nbr == 0)
		return ;
	div = nbr / base_size;
	mod = nbr % base_size;
	change_base(div, base_size, base);
	write(1, base + mod, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				base_size;
	unsigned int	num;

	base_size = ft_strlen(base);
	if (base_size <= 1)
		return ;
	if (check_duplicate(base, base_size))
		return ;
	if (check_mark(base, base_size))
		return ;
	if (nbr == 0)
		write(1, base, 1);
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	num = (unsigned int)nbr;
	change_base(num, base_size, base);
}
