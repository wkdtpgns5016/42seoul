/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_valid.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoon <jiyoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:55:37 by jiyoon            #+#    #+#             */
/*   Updated: 2022/01/23 20:55:24 by jihopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	print_dict_error(void)
{
	write(1, "Dict Error\n", 11);
	return (0);
}

int	check_colon(char c)
{
	if (c != ':')
	{
		return (0);
	}
	return (1);
}

char	*check_num_space(char *str)
{
	if (!is_num(str[0]))
	{
		print_dict_error();
		return (0);
	}
	while (is_num(*str))
		str++;
	while (is_space(*str))
		str++;
	if (!check_colon(*str++))
	{
		print_dict_error();
		return (0);
	}
	return (str);
}

char	*move_valid(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '\0')
	{
		print_dict_error();
		return (0);
	}
	while (32 <= *str && *str <= 126)
		str++;
	return (str);
}

int	is_dict_valid(char **arr)
{
	int		i;
	char	*str;

	i = -1;
	if (*arr == 0)
		return (0);
	while (arr[++i])
	{
		str = arr[i];
		str = check_num_space(str);
		if (str == 0)
			return (0);
		str = move_valid(str);
		if (str == 0)
			return (0);
		if (*str != '\0')
		{
			print_dict_error();
			return (0);
		}
	}
	return (1);
}
