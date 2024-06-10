# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 14:54:53 by yutsong           #+#    #+#              #
#    Updated: 2024/06/10 12:43:39 by yutsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	./end_game.c
				./get_next_line.c
				./init_game.c
				./move_dorong.c
				./printer.c
				./so_ling.c
				./utils_get_next_line.c
				./utils_map.c
				./utils_map2.c
				./utils.c
OBJS		=	$(SRCS:.c=.o)

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