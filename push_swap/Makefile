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
SRCS = 	main.c \
		push_swap.c \
		push_swap_utils.c \
		push_swap_utils2.c \
		check_vaild_arg.c \
		dlist_op_utils.c \
		deque_op_utils.c \
		deque_op_utils2.c \
		ft_free.c \
		ft_atol.c \
		parsing_arg_utils.c \
		parsing_arg.c \
		stack_op_push.c \
		stack_op_reverse_rotate.c \
		stack_op_rotate.c \
		stack_op_swap.c \
		stack_op_utils.c \
		stack_op_utils2.c

OBJS = $(SRCS:.c=.o)

AR = ar -rc
HEAD = ./
LIBFT = libft/libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@

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
