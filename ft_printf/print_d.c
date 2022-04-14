/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:30:34 by sehjang           #+#    #+#             */
/*   Updated: 2022/04/14 18:30:35 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	print_d(t_format *format, int value)
{
	int		len;
	char	*str;

	str = add_precision_d(format, value);
	if (str == 0)
		return (-1);
	if (add_flag_gsp_d(format, value, &str) < 0)
		return (-1);
	if (add_flag_zd(format, &str) < 0)
		return (-1);
	len = ft_strlen(str);
	len += print_width(format->width, len);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
