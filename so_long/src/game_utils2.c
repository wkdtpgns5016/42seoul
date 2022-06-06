#include "../include/so_long.h"
#include <stdio.h>

void	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	clear_game(t_game *game)
{
	printf("Game Clear! You took %d steps.\n", game->player->walk);
	exit_game(game);
}
