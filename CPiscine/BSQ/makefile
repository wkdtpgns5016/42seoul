CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ft_atoi.c ft_gets.c ft_putchar.c mapping.c change_map.c ft_fget_map.c	ft_max.c ft_putstr.c main.c  print_map.c ft_fget_name.c ft_min.c ft_strdup.c make_square.c select_square.c ft_get_nbr.c ft_put_error.c ft_strlen.c map_maker.pl sort_point.c
OBJS	= ${SRCS:.c=.o}
NAME	= bsq
RM		= rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean
