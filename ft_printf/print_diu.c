/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:30:34 by sehjang           #+#    #+#             */
/*   Updated: 2022/04/14 18:30:35 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	print_value(char **str, int length)
{
	int	len;

	len = ft_strlen(*str);
	if (len + length < 2147483647)
	{
		ft_putstr_fd(*str, 1);
		free(*str);
		return (len);
	}
	free(*str);
	return (-1);
}

int	print_d(t_format *format, int value, int length)
{
	int		len;
	char	*str;
	char	*num;

	num = ft_itoa(value);
	if (num == 0)
		return (-1);
	str = add_precision_num(format, num);
	if (str == 0)
		return (-1);
	if (add_flag_gsp_d(format, value, &str) < 0)
		return (-1);
	if (add_flag_zd(format, &str) < 0)
		return (-1);
	str = add_width(format, &str);
	if (str == 0)
		return (-1);
	len = print_value(&str, length);
	return (len);
}

int	print_i(t_format *format, int value, int length)
{
	int		len;

	len = print_d(format, value, length);
	return (len);
}

int	print_u(t_format *format, unsigned int value, int length)
{
	int		len;
	char	*str;
	char	*num;

	num = ft_uitoa(value);
	if (num == 0)
		return (-1);
	str = add_precision_num(format, num);
	if (str == 0)
		return (-1);
	if (add_flag_zd(format, &str) < 0)
		return (-1);
	str = add_width(format, &str);
	if (str == 0)
		return (-1);
	len = print_value(&str, length);
	return (len);
}
