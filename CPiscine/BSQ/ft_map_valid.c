/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_vaild.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:30:23 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/27 11:13:40 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_include(char **map, char a, char b)
{
	int	i;
	int	j;

	i = 1;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != 0)
		{
			if (map[i][j] != a && map[i][j] != b)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}		

int	check_eqal_row(char **map)
{
	int	i;

	i = 1;
	while (map[i + 1] != 0)
	{
		if (ft_strlen(map[i + 1]) != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	print_availble_map(char *info, int size)
{
	int	i;

	i = 0;
	if (info[size - 1] < 32 || info[size - 2] > 126)
		return (0);
	if (info[size - 2] < 32 || info[size - 2] > 126)
		return (0);
	if (info[size - 3] < 32 || info[size - 3] > 126)
		return (0);
	return (1);
}

int	ft_map_vaild(char	**map, int len)
{
	int	size;
	int	row;

	row = 0;
	if (map == 0)
		return (0);
	while (map[row] != 0)
		row++;
	if (row - 1 < 1 || row - 1 != len)
		return (0);
	size = ft_strlen(map[0]);
	if (size < 4)
		return (0);
	if (map[0][size - 1] == map[0][size - 2] || \
		map[0][size - 1] == map[0][size - 3] || \
		map[0][size - 2] == map[0][size - 3])
		return (0);
	if (!print_availble_map(map[0], size) || !check_eqal_row(map))
		return (0);
	if (!is_include(map + 1, map[0][size - 2], map[0][size - 3]))
		return (0);
	return (1);
}
