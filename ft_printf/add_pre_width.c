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

char	*add_precision_num(t_format *format, char *num)
{
	char	*zero;
	char	*temp;
	int		i;

	if (format->precision - (int)ft_strlen(num) > 0)
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

char	*add_width(t_format *format, char **str)
{
	int		size;
	int		len;
	char	*dash;
	char	*temp;

	len = ft_strlen(*str);
	size = format->width - len;
	if (size > 0)
	{
		dash = (char *)malloc(sizeof(char) * size + 1);
		if (dash == 0)
			return (0);
		ft_memset(dash, ' ', size);
		dash[size] = '\0';
		temp = ft_strjoin(dash, *str);
		free(dash);
		free(*str);
		return (temp);
	}
	return (*str);
}
