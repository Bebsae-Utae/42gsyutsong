# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 14:54:53 by yutsong           #+#    #+#              #
#    Updated: 2024/06/11 12:58:38 by yutsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

SRC_DIR		=	./src
OBJ_DIR		=	./obj
INC_DIR		=	./include ./minilibx

SRCS		=	$(wildcard $(SRC_DIR)/*.c)
OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

INCLUDES	=	$(addprefix -I, $(INC_DIR))
LIBS		=	-L./minilibx-linux -lmlx -lm -lX11 -lXext

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

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