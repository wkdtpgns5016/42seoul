/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:08:43 by sehjang           #+#    #+#             */
/*   Updated: 2022/06/07 16:08:43 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_img	*read_img(void *mlx)
{
	t_img	*img;
	int		img_width;
	int		img_height;

	img = (t_img *)malloc(sizeof(t_img));
	if (img == 0)
		return (0);
	img->player = mlx_xpm_file_to_image(mlx, "./resources/img/character.xpm", \
	&img_width, &img_height);
	img->item = mlx_xpm_file_to_image(mlx, "./resources/img/item.xpm", \
	&img_width, &img_height);
	img->door = mlx_xpm_file_to_image(mlx, "./resources/img/door.xpm", \
	&img_width, &img_height);
	img->grass = mlx_xpm_file_to_image(mlx, "./resources/img/grass.xpm", \
	&img_width, &img_height);
	img->wall = mlx_xpm_file_to_image(mlx, "./resources/img/wall.xpm", \
	&img_width, &img_height);
	if (img->player == 0 || img->item == 0 || img->door == 0 || img->grass == 0 \
	|| img->wall == 0)
		error_message("Error\nImage file not found\n");
	return (img);
}

static void	set_player(t_player *player, t_map *map)
{
	int	i;

	i = 0;
	player->score = 0;
	player->walk = 0;
	while (i < (int)ft_strlen(map->str))
	{
		if (map->str[i] == 'P')
		{
			player->x = i % map->width;
			player->y = map->height - 1;
		}
		i++;
	}
}

static t_player	*make_player(t_map *map)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (player == 0)
		return (0);
	set_player(player, map);
	return (player);
}

t_game	*make_game(char *file)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (game == 0)
		return (0);
	game->map = make_map(file);
	check_map(game->map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, \
		game->map->width * 32, game->map->height * 32, "so_long");
	if (game->mlx == 0 || game->win == 0)
	{
		ft_free(game->mlx);
		ft_free(game->win);
		return (0);
	}
	game->img = read_img(game->mlx);
	game->player = make_player(game->map);
	if (game->img == 0 || game->player == 0)
	{
		ft_free(game->img);
		ft_free(game->player);
		return (0);
	}
	return (game);
}
