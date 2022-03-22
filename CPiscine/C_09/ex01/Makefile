# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 10:36:59 by sehjang           #+#    #+#              #
#    Updated: 2022/01/26 12:50:31 by sehjang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS=${addprefix ${SRC_DIR}, ${SRC}}
OBJS=${SRCS:.c=.o}
SRC_DIR=./srcs/
HEAD= ./includes/
NAME=libft.a
AR=ar rc
RAN=ranlib
RM=rm -f
CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: ${NAME}

.c.o:
			${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
			${AR} ${NAME} ${OBJS}
			${RAN} ${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

