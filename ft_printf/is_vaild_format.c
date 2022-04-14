/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_vaild_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:27:25 by sehjang           #+#    #+#             */
/*   Updated: 2022/04/14 18:27:27 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	is_include_flag(char *flags, char *check)
{
	if (flags == 0)
		return (1);
	while (*flags != 0)
	{
		if (ft_strchr(check, *flags) == 0)
			return (0);
		flags++;
	}
	return (1);
}

static int	is_flag_to_type(t_format *format)
{
	if (format->type == 'c' || format->type == 's' || format->type == 'p')
		return (is_include_flag(format->flags, "-"));
	else if (format->type == 'd' || format->type == 'i')
		return (is_include_flag(format->flags, "-0 +"));
	else if (format->type == 'u')
		return (is_include_flag(format->flags, "-0"));
	else if (format->type == 'x' || format->type == 'X')
		return (is_include_flag(format->flags, "-0#"));
	else
		return (is_include_flag(format->flags, ""));
}

static int	is_duplicate_flag(char *flags)
{
	if (flags == 0)
		return (1);
	while (*flags != 0)
	{
		if (*flags == '-' || *flags == '0')
		{
			if (ft_strchr(flags + 1, '-') != 0 || \
ft_strchr(flags + 1, '0') != 0)
				return (0);
		}
		else if (*flags == ' ' || *flags == '#' || *flags == '+')
		{
			if (ft_strchr(flags + 1, ' ') != 0 || \
ft_strchr(flags + 1, '#') != 0 || ft_strchr(flags + 1, '+'))
				return (0);
		}
		flags++;
	}
	return (1);
}

static int	is_precision_to_type(t_format *format)
{
	if (format->type == 'c' || format->type == 'p' || format->type == '%')
	{
		if (format->precision > 0)
			return (0);
	}
	return (1);
}

int	is_vaild_format(t_format *format)
{
	if (!is_type_char(format->type))
		return (0);
	if (!is_flag_to_type(format))
		return (0);
	if (!is_precision_to_type(format))
		return (0);
	if (!is_duplicate_flag(format->flags))
		return (0);
	return (1);
}
