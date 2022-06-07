/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:08:33 by sehjang           #+#    #+#             */
/*   Updated: 2022/06/07 16:08:34 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <fcntl.h>
#include <unistd.h>

static char	*join_map(char *map, char *add)
{
	char	*join;
	char	*sub;

	if (ft_strchr(add, '\n') != 0)
		sub = ft_substr(add, 0, ft_strlen(add) - 1);
	else
		sub = ft_strdup(add);
	if (sub == 0)
		return (0);
	if (map == 0)
		join = ft_strjoin("", sub);
	else
		join = ft_strjoin(map, sub);
	ft_free(map);
	ft_free(add);
	ft_free(sub);
	if (join == 0)
		return (0);
	return (join);
}

static void	open_map_file(t_map *map, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_message("Error\nFailed to open file\n");
	line = get_next_line(fd);
	if (line == 0)
		return ;
	map->width = ft_strlen(line) - 1;
	while (line != 0)
	{
		map->height++;
		map->str = join_map(map->str, line);
		if (map->str == 0)
		{
			ft_free(map);
			break ;
		}
		line = get_next_line(fd);
		if (line == 0)
			break ;
	}
	close(fd);
}

static void	init_map(t_map *map)
{
	if (map != 0)
	{
		map->width = 0;
		map->height = 0;
		map->str = 0;
		map->item_cnt = 0;
	}
}

t_map	*make_map(char *file)
{
	t_map		*map;
	int			i;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	init_map(map);
	if (map == 0)
		return (0);
	open_map_file(map, file);
	if (map != 0)
	{
		while (i < (int)ft_strlen(map->str))
		{
			if (map->str[i] == 'C')
				map->item_cnt++;
			i++;
		}
	}
	return (map);
}
