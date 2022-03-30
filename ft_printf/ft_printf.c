/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:07:52 by sehjang           #+#    #+#             */
/*   Updated: 2022/03/29 18:33:03 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

int	get_format(t_format **format, const char *str)
{

}

t_list	*split_format(const char *format)
{
	t_list		*format_list;
	t_list		*temp;
	t_format	*fmt;
	int			fmt_len;

	while (*format != 0)
	{
		if (*format == '%')
		{
			fmt_len = get_format(&fmt, format + 1);
			if(fmt == 0)
				return (0);
			temp = ft_lstnew(fmt);
			if (temp == 0)
				return (0);
			ft_lstadd_back(&format_list, temp);
			format+=fmt_len;
		}
		else
			format++;
	}
	return (format_list);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	int a = 10;
	char *str = "string";

	printf("%%d   : %d\n", a);
	printf("%%i   : %i\n", a);
	printf("%%x   : %x\n", a);
	printf("%%X   : %X\n", a);
	printf("%%p   : %p\n", &a);
	printf("%%c   : %c\n", *str);
	printf("%%s   : %s\n", str);
	printf("%%%%   : %%\n");
	printf("%%-5d : %-5d\n", a);
	printf("%%+d  : %+d\n", a);
	printf("%%05d : %05d\n", a);
	printf("%% d  : % d\n", a);
	printf("%%5d  : %5d\n", a);
	printf("%%.5d  : %.5d\n", a);
}
