/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_format_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:31:23 by sehjang           #+#    #+#             */
/*   Updated: 2022/04/14 18:31:24 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

t_format	*fmt_new(void)
{
	t_format	*format;

	format = (t_format *)malloc(sizeof(t_format));
	if (format == 0)
		return (0);
	format->flags = "";
	format->width = 0;
	format->precision = -1;
	format->type = 0;
	format->len = 0;
	return (format);
}

void	fmt_free(t_format **format)
{
	if (ft_strlen((*format)->flags) > 0)
		free((*format)->flags);
	free(*format);
}
