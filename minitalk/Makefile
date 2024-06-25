# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 19:50:01 by yutsong           #+#    #+#              #
#    Updated: 2024/06/25 11:39:30 by yutsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minitalk
SERVER			= server
CLIENT			= client

SRC_DIR			= ./src
INC_DIR			= ./include

COMMON_FILES	= utils_ft.c utils_signal.c
SERVER_FILES	= server.c $(COMMON_FILES)
CLIENT_FILES	= client.c $(COMMON_FILES)

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