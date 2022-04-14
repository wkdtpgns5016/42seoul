/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_gsp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:22:18 by sehjang           #+#    #+#             */
/*   Updated: 2022/04/14 15:22:20 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*flag_shap(t_format *format, char **str)
{
	char	*new;

	if (format->type == 'x')
		new = ft_strjoin("0x", *str);
	else if (format->type == 'X')
		new = ft_strjoin("0X", *str);
	else
		return (*str);
	free(*str);
	if (new == 0)
		return (0);
	return (new);
}

char	*flag_plus(t_format *format, char **str, int value)
{
	char	*new;

	if (value >= 0)
	{
		new = ft_strjoin("+", *str);
		free(*str);
		if (new == 0)
			return (0);
		return (new);
	}
	return (*str);
}

char	*flag_gap(t_format *format, char **str, int value)
{
	char	*new;

	if (value >= 0)
	{
		new = ft_strjoin(" ", *str);
		free(*str);
		if (new == 0)
			return (0);
		return (new);
	}
	return (*str);
}
