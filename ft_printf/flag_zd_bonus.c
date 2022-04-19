/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:26:39 by sehjang           #+#    #+#             */
/*   Updated: 2022/04/19 14:26:40 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf_bonus.h"

static char	*flag_zero_minus(int len, char **str)
{
	char	*zero;
	char	*new;
	char	*temp;

	zero = (char *)malloc(len + 1);
	if (zero == 0)
	{
		ft_free_safe(str);
		return (0);
	}
	ft_memset(zero, '0', len);
	zero[len] = '\0';
	new = ft_strjoin(zero, (*str) + 1);
	ft_free_safe(&zero);
	ft_free_safe(str);
	if (new == 0)
		return (0);
	temp = ft_strjoin("-", new);
	ft_free_safe(&new);
	return (temp);
}

char	*flag_zero(int len, char **str)
{
	char	*zero;
	char	*new;

	if (**str == '-')
		return (flag_zero_minus(len, str));
	zero = (char *)malloc(len + 1);
	if (zero == 0)
	{
		ft_free_safe(str);
		return (0);
	}
	ft_memset(zero, '0', len);
	zero[len] = '\0';
	new = ft_strjoin(zero, *str);
	ft_free_safe(&zero);
	ft_free_safe(str);
	if (new == 0)
		return (0);
	return (new);
}

char	*flag_dash(int len, char **str)
{
	char	*dash;
	char	*new;

	dash = (char *)malloc(len + 1);
	if (dash == 0)
	{
		ft_free_safe(str);
		return (0);
	}
	ft_memset(dash, ' ', len);
	dash[len] = '\0';
	new = ft_strjoin(*str, dash);
	ft_free_safe(&dash);
	ft_free_safe(str);
	if (new == 0)
		return (0);
	return (new);
}
