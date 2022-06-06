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

void	check_crash(t_game *game, int direction)
{
	int	i;

	i = get_location_player(game);
	if (game->map->str[i - direction] == '0')
	{
		game->map->str[i] = '0';
		game->map->str[i - direction] = 'P';
		game->player->walk++;
		printf("%d\n", game->player->walk);
		set_game(game);
	}
	if (game->map->str[i - direction] == 'C')
	{
		game->player->score++;
		game->map->str[i] = '0';
		game->map->str[i - direction] = 'P';
		game->player->walk++;
		printf("%d\n", game->player->walk);
		set_game(game);
	}
	if (game->map->str[i - direction] == 'E' \
	&& game->map->item_cnt == game->player->score)
		clear_game(game);
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
