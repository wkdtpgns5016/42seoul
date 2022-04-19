/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:29:57 by sehjang           #+#    #+#             */
/*   Updated: 2022/04/19 14:29:58 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

static int	set_flag(t_format **format, const char *str)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (is_flag_char(*(str + len)))
	{
		i++;
		len++;
	}
	if (is_flag_char(*(str + len - i)))
		(*format)->flags = get_flag(str + len - i, i);
	return (len);
}

static int	set_width(t_format **format, const char *str, va_list *ap)
{
	size_t	len;

	len = 0;
	if (*(str + len) == '*')
	{
		(*format)->width = va_arg(*ap, int);
		len++;
	}
	else
	{
		while (ft_isdigit(*(str + len)))
			len++;
		if (ft_isdigit(*(str)))
			(*format)->width = get_num(str, len);
	}
	return (len);
}

static int	set_precision(t_format **format, const char *str, va_list *ap)
{
	size_t	len;

	len = 0;
	if (*(str + len) == '.')
	{
		len++;
		(*format)->precision = 0;
		if (*(str + len) == '*')
		{
			(*format)->precision = va_arg(*ap, int);
			len++;
		}
		else
		{
			while (ft_isdigit(*(str + len)))
				len++;
			if (ft_isdigit(*(str + 1)))
				(*format)->precision = get_num(str + 1, len);
		}
	}
	return (len);
}

int	set_format(t_format **format, const char *str, va_list *ap)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	len += set_flag(format, str);
	len += set_width(format, str + len, ap);
	len += set_precision(format, str + len, ap);
	if (is_type_char(*(str + len)))
		(*format)->type = *(str + len);
	len++;
	(*format)->len = (int)len;
	if (!is_vaild_format(*format))
		return (-1);
	return ((int)len);
}
