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

#include <stdio.h>


t_list	*split_format(const char *format, ...)
{
	t_list		*format_list;
	t_list		*temp;
	t_format	*fmt;
	int			fmt_len;
	va_list		ap;

	format_list = 0;
	va_start(ap, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			fmt = fmt_new();
			fmt_len = set_format(&fmt, format + 1, &ap);
			if (fmt == 0)
				return (0);
			temp = ft_lstnew(fmt);
			if (temp == 0)
				return (0);
			ft_lstadd_back(&format_list, temp);
			format += fmt_len;
		}
		else
			format++;
	}
	return (format_list);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_list	*format_list;

	format_list = split_format(format, ap);
	va_start(ap, ft_lstsize(format_list));
	return (0);
}


#include <stdio.h>

int	main(void)
{
	int a = 10;
	unsigned int b = 4294967297;
	char *str = "string";

	//printf("%%d   : %+7.4dz\n", a);
	// printf("%%i   : %.i\n", a);
	 printf("%%u   : %uz\n", b);
	// printf("%%x   : %.x\n", a);
	// printf("%%X   : %.X\n", a);
	// printf("%%p   : %.p\n", &a);
	//printf("%%c   : %*.cz\n","f", *str);
	// printf("%%s   : %s\n", str);
	// printf("%%%%   : %.%\n");
	// printf("%%-5d : %-5d\n", a);
	// printf("%%+d  : %+d\n", a);
	// printf("%%05d : %05d\n", a);
	// printf("%% d  : % d\n", a);
	// printf("%%5d  : %5d\n", a);
	// printf("%%.5d  : %.5d\n", a);

	t_format *format;
	format = fmt_new();

	int len;

	char *st2r = "u";
	len = set_format(&format, st2r, NULL);
	printf("type: %c\n", format->type);
	printf("flags: %s\n", format->flags);
	printf("len: %d\n", format->len);
	printf("precision: %d\n", format->precision);
	printf("width: %d\n\n", format->width);

	//print_c(format, 'a');
	//printf("$\n");

	t_list *list;
	t_format *format2;
	// list = split_format("%- #*.*s",3,4);
	// printf("%d\n", ft_lstsize(list));
	// while (list != 0)
	// {
	// 	format2 = (t_format *)(list->content);
	// 	printf("%c\n", format2->type);
	// 	printf("%d\n", format2->width);
	// 	printf("%d\n", format2->precision);
	// 	list = list->next;
	// }
	// int ab = 3;
	// //print_p(format, &ab);
	// printf("\n%-15p\n", &ab);

	printf("%-17pz\n", &a);
	print_u(format, b);

}
