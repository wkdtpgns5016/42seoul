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

int	print_c(t_format *format, char c)
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
	len = ft_strlen(str);
	len += print_width(format->width, len);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	print_s(t_format *format, char *value)
{
	int		len;
	char	*str;

	str = add_precision_s(format, value);
	if (str == 0)
		return (-1);
	if (add_flag_zd(format, &str) < 0)
		return (-1);
	len = ft_strlen(str);
	len += print_width(format->width, len);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	print_p(t_format *format, void *ptr)
{
	int			len;
	uintptr_t	addr;
	char		*str;
	char		*temp;

	addr = (uintptr_t)ptr;
	str = make_str_hex(addr);
	if (str == 0)
		return (-1);
	str = revrse_str(&str);
	if (str == 0)
		return (-1);
	temp = str;
	str = ft_strjoin("0x", temp);
	free(temp);
	if (str == 0)
		return (-1);
	if (add_flag_zd(format, &str) < 0)
		return (-1);
	len = ft_strlen(str);
	len += print_width(format->width, len);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
