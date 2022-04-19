/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pre_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:25:51 by sehjang           #+#    #+#             */
/*   Updated: 2022/04/19 14:25:56 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static char	*add_precision_minus(t_format *format, char **num)
{
	char	*temp;
	char	*str;
	char	*zero;
	int		i;

	temp = *num;
	str = ft_substr(temp, 1, ft_strlen(temp) - 1);
	if (str == 0)
		return (0);
	ft_free_safe(&temp);
	zero = (char *)malloc(format->precision - ft_strlen(str) + 1);
	if (zero == 0)
		return (0);
	i = 0;
	while (i < format->precision - (int)ft_strlen(str))
		zero[i++] = '0';
	zero[i] = '\0';
	temp = ft_strjoin(zero, str);
	if (temp == 0)
		return (0);
	ft_free_safe(&zero);
	ft_free_safe(&str);
	str = ft_strjoin("-", temp);
	ft_free_safe(&temp);
	return (str);
}

char	*add_precision_num(t_format *format, char **num)
{
	char	*zero;
	char	*temp;
	int		i;

	if (**num == '-' && format->precision - (int)ft_strlen((*num) + 1) > 0)
		return (add_precision_minus(format, num));
	if (format->precision - (int)ft_strlen(*num) > 0)
	{
		zero = (char *)malloc(format->precision - ft_strlen(*num) + 1);
		if (zero == 0)
			return (0);
		i = 0;
		while (i < format->precision - (int)ft_strlen(*num))
			zero[i++] = '0';
		zero[i] = '\0';
		temp = ft_strjoin(zero, *num);
		ft_free_safe(&zero);
		ft_free_safe(num);
		return (temp);
	}
	else
		return (*num);
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
		ft_free_safe(&dash);
		ft_free_safe(str);
		return (temp);
	}
	return (*str);
}
