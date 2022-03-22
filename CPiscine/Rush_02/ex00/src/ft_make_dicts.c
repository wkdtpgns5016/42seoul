/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_dicts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihopark <jihopark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:39:07 by jihopark          #+#    #+#             */
/*   Updated: 2022/01/23 20:39:41 by jihopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_dict	*create_dicts(unsigned int size)
{
	t_dict	*dicts;

	dicts = (t_dict *)malloc(sizeof(t_dict) * (size));
	return (dicts);
}

char	*delete_space_eng(char *str)
{
	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\r' || *str == '\t' || \
				*str == '\v' || *str == '\n' || *str == '\f')
			str++;
		else
			break ;
	}
	return (str);
}

t_dict	add_dict(char *str, unsigned int size)
{
	char	**arr;
	t_dict	dict;
	int		num;
	char	*eng;

	arr = ft_new_split(str);
	num = ft_atoi(arr[0]);
	eng = delete_space_eng(arr[1]);
	dict.num = num;
	dict.eng = eng;
	dict.size = size;
	return (dict);
}

t_dict	*ft_make_dicts(char **arr)
{
	unsigned int		i;
	unsigned int		size;
	t_dict				*t_dicts;
	t_dict				dict;

	i = 0;
	size = 0;
	while (arr[size] != 0)
		size++;
	t_dicts = create_dicts(size);
	if (t_dicts != 0)
	{
		while (arr[i] != 0)
		{
			dict = add_dict(arr[i], size);
			t_dicts[i] = dict;
			i++;
		}
		free(arr);
	}
	return (t_dicts);
}
