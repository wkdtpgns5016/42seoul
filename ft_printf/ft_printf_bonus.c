/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:26:56 by sehjang           #+#    #+#             */
/*   Updated: 2022/04/19 14:26:57 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

static int	controller_print(t_format *format, va_list *ap, int len)
{
	int	print_len;

	print_len = -1;
	if (format->type == 'c')
		print_len = print_c(format, va_arg(*ap, int), len);
	else if (format->type == 's')
		print_len = print_s(format, va_arg(*ap, char *), len);
	else if (format->type == 'p')
		print_len = print_p(format, va_arg(*ap, void *), len);
	else if (format->type == 'd')
		print_len = print_d(format, va_arg(*ap, int), len);
	else if (format->type == 'i')
		print_len = print_d(format, va_arg(*ap, int), len);
	else if (format->type == 'u')
		print_len = print_u(format, va_arg(*ap, unsigned int), len);
	else if (format->type == 'x')
		print_len = print_x(format, va_arg(*ap, unsigned int), len);
	else if (format->type == 'X')
		print_len = print_x(format, va_arg(*ap, unsigned int), len);
	else if (format->type == '%')
		print_len = print_per(format, len);
	return (print_len);
}

static int	start_printf(const char **format, va_list *ap, int *len)
{
	t_format	*fmt;
	int			print_len;

	fmt = fmt_new();
	if (fmt == 0)
		return (-1);
	if (set_format(&fmt, (*format) + 1, ap) < 0)
	{
		fmt_free(&fmt);
		return (-1);
	}
	print_len = controller_print(fmt, ap, *len);
	*format += fmt->len + 1;
	fmt_free(&fmt);
	if (print_len < 0)
		return (-1);
	return (print_len);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	int			print_len;

	len = 0;
	va_start(ap, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			print_len = start_printf(&format, &ap, &len);
			if (print_len == -1)
				return (-1);
			len += print_len;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
			len++;
		}
	}
	return (len);
}
