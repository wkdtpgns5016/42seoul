/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:08:16 by sehjang           #+#    #+#             */
/*   Updated: 2022/06/07 16:08:18 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

int	get_location_player(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->width * game->map->height)
	{
		if (game->map->str[i] == 'P')
			break ;
		i++;
	}
	return (i);
}

void	walk_player(t_game *game, int src, int dst)
{
	game->map->str[src] = '0';
	game->map->str[dst] = 'P';
	game->player->walk++;
	printf("%d\n", game->player->walk);
}

void	check_crash(t_game *game, int direction)
{
	int	i;

	i = get_location_player(game);
	if (game->map->str[i - direction] == '0')
	{
		walk_player(game, i, i - direction);
		set_game(game);
	}
	if (game->map->str[i - direction] == 'C')
	{
		game->player->score++;
		walk_player(game, i, i - direction);
		set_game(game);
	}
	if (game->map->str[i - direction] == 'E' \
	&& game->map->item_cnt == game->player->score)
	{
		walk_player(game, i, i - direction);
		clear_game(game);
	}
}

void	move_player(t_game *game, int flag)
{
	if (flag == 1)
	{
		check_crash(game, game->map->width);
		game->player->y++;
	}
	else if (flag == 2)
	{
		check_crash(game, -game->map->width);
		game->player->y--;
	}
	else if (flag == 3)
	{
		check_crash(game, -1);
		game->player->x++;
	}
	else if (flag == 4)
	{
		check_crash(game, 1);
		game->player->x--;
	}
}
