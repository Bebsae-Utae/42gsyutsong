# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 15:45:44 by yutsong           #+#    #+#              #
#    Updated: 2024/09/20 14:39:42 by yutsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRC_DIR		=	./src
OBJ_DIR		=	./obj

INC_DIR		=	./include

SRCS		=	$(wildcard $(SRC_DIR)/*.c)
OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

INCLUDES	=	$(addprefix -I, $(INC_DIR))

DATARACE	=	-g -fsanitize=thread

all: ${NAME}
$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	# $(CC) $(CFLAGS) $(DATARACE) $(INCLUDES) -c $< -o $@
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
