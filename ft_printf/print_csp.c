/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:30:25 by sehjang           #+#    #+#             */
/*   Updated: 2022/04/14 18:30:26 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdint.h>
#include <stdlib.h>

int	print_c(t_format *format, char c, int length)
{
	int		len;
	char	*str;

	str = (char *)malloc(sizeof(char) + 1);
	if (str == 0)
		return (-1);
	ft_memset(str, c, sizeof(char));
	str[1] = '\0';
	if (add_flag_zd(format, &str) < 0)
		return (-1);
	str = add_width(format, &str);
	if (str == 0)
		return (-1);
	len = print_value(&str, length);
	return (len);
}

int	print_s(t_format *format, char *value, int length)
{
	int		len;
	char	*str;
	char	*temp;

	temp = value;
	if (temp == 0)
		temp = ft_strdup("(null)");
	if (temp == 0)
		return (-1);
	str = add_precision_s(format, temp);
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

static char	*convert_addr(uintptr_t addr)
{
	char	*str;
	char	*temp;

	str = make_str_addr(addr);
	if (str == 0)
		return (0);
	str = revrse_str(&str);
	if (str == 0)
		return (0);
	temp = str;
	str = ft_strjoin("0x", temp);
	free(temp);
	if (str == 0)
		return (0);
	return (str);
}

int	print_p(t_format *format, void *ptr, int length)
{
	int			len;
	char		*str;

	str = convert_addr((uintptr_t)ptr);
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
