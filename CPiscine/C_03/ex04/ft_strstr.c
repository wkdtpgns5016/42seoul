/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:53:21 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/16 13:28:23 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*str_pos;
	char	*to_find_pos;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			str_pos = str;
			to_find_pos = to_find;
			while (*to_find_pos == *str_pos)
			{
				if (*to_find_pos == '\0')
					return (str);
				to_find_pos++;
				str_pos++;
			}
			if (*to_find_pos == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}
