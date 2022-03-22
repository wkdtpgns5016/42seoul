/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:44:07 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/17 20:28:13 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char hex)
{
	write(1, "\\", 1);
	write(1, &"0123456789abcdef"[hex / 16], 1);
	write(1, &"0123456789abcdef"[hex % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	*arr;

	i = 0;
	arr = (unsigned char *)str;
	while (arr[i] != '\0')
	{
		if (arr[i] >= 32 && arr[i] <= 126)
			write(1, &arr[i], 1);
		else
			print_hex(arr[i]);
		i++;
	}
}
