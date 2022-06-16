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

SRCS = 	srcs/pipex.c 
OBJS = $(SRCS:.c=.o)

HEAD = ./include
LIBFT = -Llibs/libft -lft

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@

$(LIBFT):
	$(MAKE) -C ./libs/libft bonus

$(NAME): $(LIBFT) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	$(MAKE) -C ./libs/libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ./libs/libft fclean
	rm -f $(NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all

.PHONY = all clean fclean re
