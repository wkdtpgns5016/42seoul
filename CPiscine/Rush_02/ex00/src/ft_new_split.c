/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:33:56 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/23 19:09:16 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	insert_new_word(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char	*first_word(char **arr, char *str)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] != ':')
		i++;
	word = (char *)malloc(sizeof(char *) * (i + 1));
	if (word == 0)
	{
		arr = 0;
		return (0);
	}
	insert_new_word(word, str, i);
	return (word);
}

void	start_new_split(char **arr, char *str)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] != ':')
		i++;
	word = first_word(arr, str);
	if (word == 0)
		return ;
	arr[0] = word;
	str = &str[++i];
	i = 0;
	while (str[i] != '\0')
		i++;
	word = (char *)malloc(sizeof(char *) * (i + 1));
	if (word == 0)
	{
		free(arr[0]);
		arr = 0;
		return ;
	}
	insert_new_word(word, str, i);
	arr[1] = word;
	arr[2] = 0;
}

char	**ft_new_split(char *str)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (3));
	if (arr != 0)
		start_new_split(arr, str);
	return (arr);
}
