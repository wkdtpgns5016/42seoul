/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:06:30 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/27 16:05:20 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		if (base[i] == ' ' || base[i] == '\f' || base[i] == '\n' || \
				base[i] == '\r' || base[i] == '\t' || base[i] == '\v' || \
				base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (i);
}

int	is_include(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	change_base(char *str, char *base, int base_size)
{
	int	num;
	int	base_idx;

	num = 0;
	base_idx = is_include(*str, base);
	while (base_idx != -1)
	{
		num = (num * base_size) + base_idx;
		str++;
		base_idx = is_include(*str, base);
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	mark;
	int	num;
	int	base_size;

	num = 0;
	mark = 1;
	base_size = check_base(base);
	if (base_size < 2)
		return (0);
	while (*str == ' ' || *str == '\f' || *str == '\n' || \
		*str == '\r' || *str == '\t' || *str == '\v')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			mark *= -1;
		str++;
	}
	num = change_base(str, base, base_size);
	return (num * mark);
}
