/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:20:31 by sehjang           #+#    #+#             */
/*   Updated: 2022/06/02 21:20:31 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "get_next_line.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_player
{
	int		x;
	int		y;
	int		score;
	int		walk;
}	t_player;

typedef struct s_map
{
	int			width;
	int			height;
	int			item_cnt;
	char		*str;
}	t_map;

typedef struct s_img
{
	void		*grass;
	void		*wall;
	void		*item;
	void		*door;
	void		*player;
}	t_img;

typedef struct s_game
{
	t_map		*map;
	t_player	*player;
	t_img		*img;
	void		*mlx;
	void		*win;
}	t_game;

void	error_message(char *message);
t_map	*make_map(char *file);
void	check_map(t_map *map);
t_game	*make_game(char *file);
void	start_game(t_game *game);
void	set_game(t_game *game);
void	exit_game(t_game *game);
void	clear_game(t_game *game);
void	move_player(t_game *game, int flag);

#endif
