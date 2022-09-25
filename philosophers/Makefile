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

NAME = philo

SRCS = 

SRCS_MANDATORY = srcs/ft_free.c \
				 srcs/monitor.c \
				 srcs/main.c \
				 srcs/philo.c \
				 srcs/philo_utils.c \
				 srcs/philo_action.c \
				 srcs/philo_action2.c \
				 srcs/parsing.c \
				 srcs/utils.c 
SRCS_BONUS = 

OBJS = $(SRCS:.c=.o)
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJS += $(OBJS_BONUS)
else
	OBJS += $(OBJS_MANDATORY)
endif

HEAD = ./philo/include

all: $(NAME)

%.o: %.c
	$(CC) -g $(CFLAGS) -c -I $(HEAD) $< -o $@

$(NAME): $(OBJS)
	$(CC) -g -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all

bonus:
	$(MAKE) WITH_BONUS=1 all

.PHONY = all clean fclean re bonus
