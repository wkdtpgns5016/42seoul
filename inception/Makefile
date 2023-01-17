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

SRCS = ./srcs
CF = $(SRCS)/docker-compose.yaml
DC = docker compose -f $(CF)

all: up

ps:
	$(DC) ps

up: 
	bash $(SRCS)/requirements/tools/make_dir.sh
	$(DC) up --build

down: 
	$(DC) down

start: 
	$(DC) start

stop: 
	$(DC) stop

clean: 
	$(MAKE) down
	bash $(SRCS)/requirements/tools/clean.sh

fclean:
	$(MAKE) clean
	docker system prune -a
		
.PHONY = all up down start stop clean fclean
