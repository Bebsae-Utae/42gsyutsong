# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 14:54:53 by yutsong           #+#    #+#              #
#    Updated: 2024/05/23 14:41:31 by yutsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
  
SRCS		= ./main.c
OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	@$(CC) -L./minilibx-linux -lmlx -lm -lX11 -lXext

%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJS)
fclean:		clean
	@rm -f $(NAME)
re:			fclean all

.PHONY:	all clean fclean re