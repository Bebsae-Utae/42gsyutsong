# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 18:19:33 by yutsong           #+#    #+#              #
#    Updated: 2024/08/10 17:16:14 by yutsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRC_DIR		=	./src
OBJ_DIR		=	./obj

INC_DIR		=	./include

SRCS		=	$(wildcard $(SRC_DIR)/*.c)
OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

INCLUDES	=	$(addprefix -I, $(INC_DIR))

all: ${NAME}
$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
