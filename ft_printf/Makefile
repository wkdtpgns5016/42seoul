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
		print_x.c 

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
		print_x_bonus.c 

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

AR = ar -rc
HEAD = ./
LIBFT = libft

mandatory: $(OBJS)
	$(MAKE) all -C ./$(LIBFT)
	cp libft/libft.a ./$(NAME)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	$(MAKE) all -C ./$(LIBFT)
	cp libft/libft.a ./$(NAME)
	$(AR) $(NAME) $(OBJS_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(HEAD) -I $(LIBFT) $< -o $@

$(NAME): mandatory

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re bonus
