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

NAME = pipex

SRCS = 	srcs/pipex.c \
		srcs/pipex_utils.c \
		srcs/ft_free.c \
		srcs/main.c

SRCS_BONUS = srcs/pipex_bonus.c \
		srcs/pipex_utils.c \
		srcs/ft_free.c \
		srcs/main.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(OBJS_BONUS)
else
	OBJECTS = $(OBJS)
endif

HEAD = ./include

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@

$(NAME): $(OBJECTS)
	$(MAKE) -C ./libft bonus
	$(CC) -o $(NAME) $(OBJECTS) -Llibft -lft

clean:
	$(MAKE) -C ./libft clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all

bonus:
	$(MAKE) WITH_BONUS=1 all

.PHONY = all clean fclean re bonus
