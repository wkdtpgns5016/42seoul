# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehjang <sehjang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 17:49:11 by sehjang           #+#    #+#              #
#    Updated: 2022/05/10 17:49:12 by sehjang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp \
	   Contact.cpp \
	   PhoneBook.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = a.out
HEAD = .

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all

.PHONY = all clean fclean re
