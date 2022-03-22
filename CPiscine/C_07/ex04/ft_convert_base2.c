/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:25:47 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/25 19:58:15 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (*str++ != '\0')
		i++;
	return (i);
}

int	check_isspace(char str)
{
	if (str == ' ' || str == '\n' || str == '\t')
		return (1);
	if (str == '\r' || str == '\v' || str == '\f')
		return (1);
	return (0);
}

int	check_base(char *base, unsigned int base_size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < base_size)
	{
		if (check_isspace(base[i]))
			return (1);
		if (base[i] == '+' || base[i] == '-')
			return (1);
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

int	change_nbr_base(char *str, char *base, int base_size)
{
	int	num;
	int	count;
	int	j;

	num = 0;
	while (*str != '\0')
	{
		count = 0;
		j = 0;
		while (base[j] != '\0')
		{
			if (base[j] == *str)
			{
				num = num * base_size;
				num = num + j;
			}
			else
				count++;
			if (count == base_size)
				return (num);
			j++;
		}
		str++;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	base_size;
	int				num;
	int				mark;

	num = 0;
	mark = 1;
	base_size = ft_strlen(base);
	if (base_size <= 1)
		return (0);
	if (check_base(base, base_size))
		return (0);
	while (check_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			mark *= -1;
		str++;
	}
	num = change_nbr_base(str, base, base_size);
	return (num * mark);
}
