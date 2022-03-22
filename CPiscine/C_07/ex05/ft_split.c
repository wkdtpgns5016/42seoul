/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:33:56 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/25 20:01:56 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_include(char	c,	char *charset)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (1);
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!is_include(str[i], charset) && is_include(str[i + 1], charset))
			count++;
		i++;
	}
	return (count);
}

void	insert_word(char *arr, char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
}

void	start_split(char **arr, char *str, char *charset, int arr_idx)
{
	int	i;
	int	str_size;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_include(str[i], charset))
		{
			str_size = 0;
			while (!is_include(str[i + str_size], charset))
				str_size++;
			arr[arr_idx] = (char *)malloc(sizeof(char) * (str_size + 1));
			if (arr[arr_idx] == 0)
			{
				arr = 0;
				return ;
			}
			insert_word(arr[arr_idx], str + i, str_size);
			arr_idx++;
			i += str_size;
		}
		else
			i++;
	}
	arr[arr_idx] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		size;
	int		arr_idx;

	size = word_count(str, charset);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (arr == 0)
		return (0);
	arr_idx = 0;
	start_split(arr, str, charset, arr_idx);
	return (arr);
}
