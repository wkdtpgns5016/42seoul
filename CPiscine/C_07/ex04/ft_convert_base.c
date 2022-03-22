/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:22:11 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/25 19:58:24 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern unsigned int	ft_strlen(char *str);
extern int			check_base(char *base, unsigned int base_size);
extern int			ft_atoi_base(char *str, char *base);
extern int			check_isspace(char str);

int	get_size(unsigned int nbr, int base_size)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= (unsigned int)base_size;
		count++;
	}
	return (count);
}

char	*change_str_base(int nbr, int base_size, char *base, int mark)
{
	unsigned int	num;
	char			*arr;
	int				i;
	int				size;

	size = 0;
	if (nbr < 0)
	{
		size++;
		nbr *= -1;
	}
	num = (unsigned int)nbr;
	size += get_size(num, base_size);
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (arr == 0)
		return (0);
	i = -1;
	while (++i < size)
	{
		arr[size - 1 - i] = base[num % base_size];
		num /= base_size;
	}
	if (mark < 0)
		arr[0] = '-';
	return (arr);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int	base_size;
	int	mark;

	mark = 1;
	if (nbr < 0)
		mark *= -1;
	base_size = ft_strlen(base);
	if (base_size <= 1)
		return (0);
	if (check_base(base, base_size))
		return (0);
	return (change_str_base(nbr, base_size, base, mark));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_size;
	int		num;
	char	*arr;

	base_size = ft_strlen(base_from);
	if (base_size <= 1)
		return (0);
	if (check_base(base_from, base_size))
		return (0);
	num = ft_atoi_base(nbr, base_from);
	arr = ft_putnbr_base(num, base_to);
	return (arr);
}
