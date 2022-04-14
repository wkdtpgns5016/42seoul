/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flag_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:17:38 by sehjang           #+#    #+#             */
/*   Updated: 2022/04/14 20:17:39 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*add_precision_d(t_format *format, int value)
{
	char	*num;
	char	*zero;
	char	*temp;
	int		i;

	num = ft_itoa(value);
	if (num == 0)
		return (0);
	if (format->precision - (int)ft_strlen(num) > 1)
	{
		zero = (char *)malloc(format->precision - ft_strlen(num) + 1);
		if (zero == 0)
			return (0);
		i = 0;
		while (i < format->precision - ft_strlen(num))
			zero[i++] = '0';
		zero[i] = '\0';
		temp = ft_strjoin(zero, num);
		free(zero);
		free(num);
		return (temp);
	}
	else
		return (num);
}

char	*add_precision_u(t_format *format, unsigned int value)
{
	char	*num;
	char	*zero;
	char	*temp;
	int		i;

	num = ft_uitoa(value);
	if (num == 0)
		return (0);
	if (format->precision - (int)ft_strlen(num) > 1)
	{
		zero = (char *)malloc(format->precision - ft_strlen(num) + 1);
		if (zero == 0)
			return (0);
		i = 0;
		while (i < format->precision - ft_strlen(num))
			zero[i++] = '0';
		zero[i] = '\0';
		temp = ft_strjoin(zero, num);
		free(zero);
		free(num);
		return (temp);
	}
	else
		return (num);
}

char	*add_precision_s(t_format *format, char *value)
{
	int		len;
	char	*str;

	len = ft_strlen(value);
	if (format->precision < len)
		len = format->precision;
	str = ft_substr(value, 0, len);
	return (str);
}

int	print_width(int width, int len)
{
	int	size;

	size = 0;
	while (len++ < width)
	{
		ft_putchar_fd(' ', 1);
		size++;
	}
	return (size);
}
