# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 17:49:11 by sehjang           #+#    #+#              #
#    Updated: 2022/05/10 17:49:12 by sehjang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = so_long

SRCS = 	src/main.c \
		src/get_next_line.c \
		src/get_next_line_utils.c \
		src/make_map.c \
		src/check_map.c \
		src/make_game.c \
		src/game_utils.c \
		src/game_utils2.c \
		src/player_utils.c
OBJS = $(SRCS:.c=.o)

HEAD = ./include

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C ./lib/libft bonus
	$(MAKE) -C ./lib/mlx
	$(CC) -o $(NAME) $(OBJS) -Llib/libft -lft -Llib/mlx -lmlx -framework OpenGL -framework AppKit

clean:
	$(MAKE) -C ./lib/libft clean
	$(MAKE) -C ./lib/mlx clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ./lib/libft fclean
	$(MAKE) -C ./lib/mlx fclean
	rm -f $(NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all

.PHONY = all clean fclean re
