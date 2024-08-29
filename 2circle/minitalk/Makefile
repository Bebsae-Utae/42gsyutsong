# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 19:50:01 by yutsong           #+#    #+#              #
#    Updated: 2024/06/26 11:16:50 by yutsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minitalk
SERVER			= server
CLIENT			= client

SRC_DIR			= ./src
INC_DIR			= ./include

SERVER_FILES	= server.c utils_server.c utils_ft.c
CLIENT_FILES	= client.c utils_client.c utils_ft.c

SERVER_OBJS		= $(SERVER_FILES:.c=.o)
CLIENT_OBJS		= $(CLIENT_FILES:.c=.o)

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
IFLAGS			= -I$(INC_DIR)
RM				= rm -rf

all				: $(NAME)

$(NAME)			: $(SERVER) $(CLIENT)

$(SERVER)		: $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) -o $(SERVER)

$(CLIENT)		: $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) -o $(CLIENT)

%.o	: $(SRC_DIR)/%.c $(INC_DIR)/minitalk.h
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean			:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean			: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all