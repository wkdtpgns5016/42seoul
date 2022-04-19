# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 14:28:17 by sehjang           #+#    #+#              #
#    Updated: 2022/04/19 14:28:18 by sehjang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRCS = ft_printf.c \
		t_format_utils.c \
		set_format.c \
		set_format_utils.c \
		is_vaild_format.c \
		flag_gsp.c \
		flag_zd.c \
		add_flag.c \
		add_pre_width.c \
		ft_uitoa.c \
		hex_utils.c \
		print_csp.c \
		print_diu.c \
		print_per.c \
		print_x.c \
		ft_free_safe.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ft_printf_bonus.c \
		t_format_utils_bonus.c \
		set_format_bonus.c \
		set_format_utils_bonus.c \
		is_vaild_format_bonus.c \
		flag_gsp_bonus.c \
		flag_zd_bonus.c \
		add_flag_bonus.c \
		add_pre_width_bonus.c \
		ft_uitoa_bonus.c \
		hex_utils_bonus.c \
		print_csp_bonus.c \
		print_diu_bonus.c \
		print_per_bonus.c \
		print_x_bonus.c \
		ft_free_safe_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(OBJS_BONUS)
else
	OBJECTS = $(OBJS)
endif

AR = ar -rc
HEAD = ./
LIBFT = libft/libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(HEAD) -I $(LIBFT) $< -o $@
	
bonus: 
	make WITH_BONUS=1 all

$(LIBFT) : 
	make -C ./libft

$(NAME): $(LIBFT) $(OBJECTS)
	cp libft/libft.a ./$(NAME)
	$(AR) $(NAME) $(OBJECTS)

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re bonus
