/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:36:46 by sehjang           #+#    #+#             */
/*   Updated: 2022/06/02 20:36:47 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_message(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	check_arg(int args, char **argc)
{
	char	*extension;

	if (args != 2)
		error_message("Error\nInvalid argument: Wrong number of arguments\n");
	extension = ft_strrchr(argc[1], '.');
	if (extension == 0)
		error_message("Error\nInvalid argument: Wrong map's extension\n");
	if (ft_strlen(extension) != 4)
		error_message("Error\nInvalid argument: Wrong map's extension\n");
	if (ft_strncmp(extension, ".ber", 4) != 0)
		error_message("Error\nInvalid argument: Wrong map's extension\n");
}

int	main(int args, char **argc)
{
	t_game	*game;

	check_arg(args, argc);
	game = make_game(argc[1]);
	if (game == 0)
		error_message("Error\nOut of memory");
	start_game(game);
}
