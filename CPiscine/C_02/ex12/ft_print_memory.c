/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:44:46 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/18 10:34:18 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	dec_to_hex(char *hex, long long dec)
{
	int			i;
	long long	mod;

	i = 0;
	while (i < 16)
	{
		mod = dec % 16;
		if (mod < 10)
			hex[i] = 48 + (int)mod;
		else
			hex[i] = 97 + ((int)mod - 10);
		dec = dec / 16;
		if (dec == 0 && i < 15)
			hex[i + 1] = '0';
		i++;
	}
}

void	print_addr(void *arr)
{
	long long	addr_hex;
	int			i;
	char		hex[16];

	addr_hex = (long long)arr;
	dec_to_hex(hex, addr_hex);
	i = 15;
	while (i >= 0)
	{
		write(1, &hex[i--], 1);
	}
	write(1, ": ", 2);
}

void	print_hex_value(unsigned char	*arr, unsigned int size)
{
	unsigned int	i;
	char			hex[16];
	long long		ascll;

	i = 0;
	while (i < size)
	{
		ascll = 0;
		while (ascll < arr[i])
			ascll++;
		dec_to_hex(hex, ascll);
		write(1, &hex[1], 1);
		write(1, &hex[0], 1);
		if (i % 2 == 1 && i > 0)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		if (i % 2 == 1 && i > 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		i++;
	}
}

void	print_value(unsigned char	*arr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (arr[i] >= 0 && arr[i] <= 31)
			arr[i] = '.';
		else if (arr[i] >= 127)
			arr[i] = '.';
		write(1, &arr[i], 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	j;
	unsigned char	*arr;
	unsigned int	s;

	j = 0;
	s = 16;
	arr = (unsigned char *)addr;
	while (j < size)
	{
		if (size - j < 16)
			s = size - j;
		print_addr(&arr[j]);
		print_hex_value(&arr[j], s);
		print_value(&arr[j], s);
		write(1, "\n", 1);
		j = j + 16;
	}
	return (addr);
}
