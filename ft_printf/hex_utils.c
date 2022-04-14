/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:16:48 by sehjang           #+#    #+#             */
/*   Updated: 2022/04/14 20:16:48 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	get_size_hex(uintptr_t num)
{
	int	size;

	size = 0;
	while (num > 0)
	{
		num /= 16;
		size++;
	}
	return (size);
}

char	*make_str_hex(uintptr_t num)
{
	char	*str;
	int		size;
	int		i;

	size = get_size_hex(num);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (num > 0)
	{
		str[i] = "0123456789abcdef"[num % 16];
		num /= 16;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*revrse_str(char **str)
{
	char	*new;
	int		str_size;
	int		new_idx;

	new_idx = 0;
	str_size = ft_strlen(*str);
	new = (char *)malloc(str_size + 1);
	if (new == 0)
		return (0);
	while (str_size > 0)
	{
		new[new_idx++] = (*str)[str_size - 1];
		str_size--;
	}
	new[new_idx] = '\0';
	free(*str);
	return (new);
}
