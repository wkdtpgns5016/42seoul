/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flag_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:26:33 by sehjang           #+#    #+#             */
/*   Updated: 2022/04/14 18:26:35 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	add_flag_gsp_d(t_format *format, int value, char **str)
{
	if (ft_strchr(format->flags, ' ') != 0)
		*str = flag_gap(format, str, value);
	else if (ft_strchr(format->flags, '+') != 0)
		*str = flag_plus(format, str, value);
	else if (ft_strchr(format->flags, '#') != 0)
	{
		if (value != 0)
			*str = flag_shap(format, str);
	}
	if (str == 0)
		return (-1);
	return (ft_strlen(*str));
}

int	add_flag_zd(t_format *format, char **str)
{
	char	*temp;
	int		len;

	len = ft_strlen(*str);
	if (format->width > len)
	{
		if (ft_strchr(format->flags, '0') != 0)
		{
			if (format->precision == -1)
				*str = flag_zero(format->width - len, str);
		}
		else if (ft_strchr(format->flags, '-') != 0)
			*str = flag_dash(format->width - len, str);
	}
	if (str == 0)
		return (-1);
	return (ft_strlen(*str));
}
