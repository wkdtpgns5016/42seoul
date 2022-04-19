/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:30:47 by sehjang           #+#    #+#             */
/*   Updated: 2022/04/19 14:30:18 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	is_flag_char(const char c)
{
	if (c == '-' || c == '0' || c == '+' || c == '#' || c == ' ')
		return (1);
	return (0);
}

int	is_type_char(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
	c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

char	*get_flag(const char *str, size_t len)
{
	char	*flag;

	flag = ft_substr(str, 0, len);
	if (flag == 0)
		return (0);
	return (flag);
}

int	get_num(const char *str, size_t len)
{
	int		n;
	char	*num;

	num = ft_substr(str, 0, len);
	if (num == 0)
		return (0);
	n = ft_atoi(num);
	ft_free_safe(&num);
	return (n);
}
