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
NAME = push_swap
SRCS = push_swap.c \
		t_stack.c

OBJS = $(SRCS:.c=.o)

AR = ar -rc
HEAD = ./
LIBFT = libft/libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(HEAD) -I $(LIBFT) $< -o $@

$(LIBFT) : 
	make -C ./libft bonus

$(NAME): $(LIBFT) $(OBJS)
	$(CC) -o $(NAME) $(LIBFT) $(OBJS)

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all

.PHONY = all clean fclean re bonus
