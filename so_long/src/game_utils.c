/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:09:02 by sehjang           #+#    #+#             */
/*   Updated: 2022/06/07 16:09:03 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	set_game_img(t_game *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->img->grass, width * 32, height * 32);
	if (game->map->str[height * game->map->width + width] == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img->wall, width * 32, height * 32);
	else if (game->map->str[height * game->map->width + width] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img->player, width * 32, height * 32);
	else if (game->map->str[height * game->map->width + width] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img->item, width * 32, height * 32);
	else if (game->map->str[height * game->map->width + width] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img->door, width * 32, height * 32);
}

void	set_game(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	while (height < game->map->height)
	{
		width = 0;
		while (width < game->map->width)
		{
			set_game_img(game, width, height);
			width++;
		}
		height++;
	}
}

static int	event_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_game(game);
	if (key_code == KEY_W)
		move_player(game, 1);
	if (key_code == KEY_S)
		move_player(game, 2);
	if (key_code == KEY_D)
		move_player(game, 3);
	if (key_code == KEY_A)
		move_player(game, 4);
	return (0);
}

void	start_game(t_game *game)
{
	set_game(game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &event_key, game);
	mlx_loop(game->mlx);
}
