#include "../include/so_long.h"

static int	check_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		if (i % map->width == 0 || i % map->width == map->width - 1)
		{
			if (map->str[i] != '1')
				return (1);
		}
		else if (i < map->width)
		{
			if (map->str[i] != '1')
				return (1);
		}
		else if (i > map->width * map->height - map->width)
		{
			if (map->str[i] != '1')
				return (1);
		}
		i++;
	}
	return (0);
}

static int	count_elements(t_map *map, int *p_c, int *i_c, int *d_c)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		if (map->str[i] != '0' && map->str[i] != '1' & map->str[i] != 'P' \
		&& map->str[i] != 'C' && map->str[i] != 'E')
			return (1);
		if (map->str[i] == 'P')
			(*p_c)++;
		if (map->str[i] == 'C')
			(*i_c)++;
		if (map->str[i] == 'E')
			(*d_c)++;
		i++;
	}
	return (0);
}

static int	check_map_elements(t_map *map)
{
	int	i;
	int	player_count;
	int	item_count;
	int	door_count;

	i = 0;
	player_count = 0;
	item_count = 0;
	door_count = 0;
	if (count_elements(map, &player_count, &item_count, &door_count))
		error_message("Error\nInvalid map:\
		There are other elements in the map\n");
	if (player_count != 1)
		return (1);
	if (item_count < 1)
		return (2);
	if (door_count < 1)
		return (3);
	return (0);
}

void	check_map(t_map *map)
{
	if (map == 0)
		error_message("Error\nInvalid map\n");
	if (map->str == 0)
		error_message("Error\nInvalid map\n");
	if (map->width * map->height != (int)ft_strlen(map->str))
		error_message("Error\nInvalid map: The map is not rectangular\n");
	if (check_wall(map))
		error_message("Error\nInvalid map: \
		The map is not surrounded by a map\n");
	if (check_map_elements(map) == 1)
		error_message("Error\nInvalid map: There can only be one player\n");
	if (check_map_elements(map) == 2)
		error_message("Error\nInvalid map: There must be at least one item\n");
	if (check_map_elements(map) == 3)
		error_message("Error\nInvalid map: There must be at least one exit\n");
}
