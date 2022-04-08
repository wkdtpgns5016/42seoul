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

#include <stdio.h>

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
	free(num);
	return (n);
}

int	set_format(t_format **format, const char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	// flag 속성
	while (is_flag_char(*(str + len)))
	{
		i++;
		len++;
	}
	if (is_flag_char(*(str + len - i)))
		(*format)->flags = get_flag(str + len - i, i);
		
	// width 속성
	i = 0;
	while (ft_isdigit(*(str + len)))
	{
		i++;
		len++;
	}
	if (ft_isdigit(*(str + len - i)))
		(*format)->width = get_num(str + len - i, i);

	// precision 속성
	i = 0;
	if (*(str + len) == '.')
	{
		len++;
		while (ft_isdigit(*(str + len)))
		{
			i++;
			len++;
		}
		if (ft_isdigit(*(str + len - i)))
			(*format)->precision = get_num(str + len - i, i);
		i = 0;
	}

	// type 속성
	if (is_type_char(*(str + len)))
		(*format)->type = *(str + len);
	len++;

	// len 속성
	(*format)->len = (int)len;
	return ((int)len);
}

t_list	*split_format(const char *str)
{
	t_list		*format_list;
	t_list		*temp;
	t_format	*fmt;
	int			fmt_len;

	format_list = 0;
	while (*str != 0)
	{
		if (*str == '%')
		{
			fmt = fmt_new();
			fmt_len = set_format(&fmt, str + 1);
			if (fmt == 0)
				return (0);
			temp = ft_lstnew(fmt);
			if (temp == 0)
				return (0);
			ft_lstadd_back(&format_list, temp);
			str += fmt_len;
		}
		else
			str++;
	}
	return (format_list);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_list	*format_list;

	format_list = split_format(format);
	va_start(ap, ft_lstsize(format_list));
	return (0);
}


#include <stdio.h>

int	main(void)
{
	int a = 10;
	char *str = "string";

	printf("%%d   : %.d\n", a);
	printf("%%i   : %.i\n", a);
	printf("%%u   : %.u\n", a);
	printf("%%x   : %.x\n", a);
	printf("%%X   : %.X\n", a);
	printf("%%p   : %.p\n", &a);
	printf("%%c   : %.c\n", *str);
	printf("%%s   : %.s\n", str);
	printf("%%%%   : %.%\n");
	printf("%%-5d : %-5d\n", a);
	printf("%%+d  : %+d\n", a);
	printf("%%05d : %05d\n", a);
	printf("%% d  : % d\n", a);
	printf("%%5d  : %5d\n", a);
	printf("%%.5d  : %.5d\n", a);

	t_format *format;
	format = fmt_new();

	int len;

	char *st2r = ".12cff";
	len = set_format(&format, st2r);
	printf("\n\ntype: %c\n", format->type);
	printf("flags: %s\n", format->flags);
	printf("len: %d\n", format->len);
	printf("precision: %d\n", format->precision);
	printf("width: %d\n\n", format->width);

	print_c(format, 'a');
	printf("$\n");

	t_list *list;
	t_format *format2;
	list = split_format("% -.5d % -.5s %i");
	printf("%d\n", ft_lstsize(list));
	while (list != 0)
	{
		format2 = (t_format *)(list->content);
		printf("%c\n", format2->type);
		list = list->next;
	}
}
