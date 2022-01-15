# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 09:33:19 by hmokhtar          #+#    #+#              #
#    Updated: 2022/01/15 10:07:47 by hmokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = funcs.c

CLIENT = client

SERVER = server

OBJS = $(SRCS:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

GREEN := $(shell tput -Txterm setaf 2)

all : $(CLIENT) $(SERVER)

%.o : %.c minitalk.h
	@$(CC) $(FLAGS) -c $<

$(CLIENT):$(OBJS)
	@$(CC) $(FLAGS) client_new.c $(OBJS) -o $(CLIENT)
	@echo $(GREEN)"DONE MAKING CLIENT"

$(SERVER):$(OBJS)
	@$(CC) $(FLAGS) server.c $(OBJS) -o $(SERVER)
	@echo $(GREEN)"DONE MAKING SERVER"

clean:
	@rm -f $(OBJS)

fclean: clean
		@rm -f $(CLIENT) $(SERVER)

re: fclean all
norm :
	@norminette *.c *.h