/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:19:13 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/25 12:05:14 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}

int	get_size(int size, char **strs, char *sep)
{
	int	i;
	int	arr_size;

	i = 0;
	arr_size = 0;
	if (size == 0)
		return (0);
	while (i < size)
	{
		arr_size += ft_strlen(strs[i]);
		if (i < size - 1)
			arr_size += ft_strlen(sep);
		i++;
	}
	return (arr_size);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		arr_size;
	char	*arr;
	char	*temp;
	int		i;

	arr_size = get_size(size, strs, sep);
	arr = (char *)malloc(sizeof(char) * (arr_size + 1));
	if (arr == 0)
		return (0);
	temp = arr;
	i = 0;
	while (i < size)
	{
		ft_strcpy(temp, strs[i]);
		temp += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(temp, sep);
			temp += ft_strlen(sep);
		}
		i++;
	}
	arr[arr_size] = '\0';
	return (arr);
}
