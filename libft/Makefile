CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRCS = 
OBJS = $(SRCS:.c=.o)

all: $(NAME)
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) 
