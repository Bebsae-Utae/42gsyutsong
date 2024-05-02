# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 16:08:27 by yutsong           #+#    #+#              #
#    Updated: 2024/05/02 16:00:20 by yutsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= gcc
CFLAG		= -Wall -Werror -Wextra

SRCS		= ft_printf.c \
				ft_printf_utils.c \
				print_percent.c \
				print_s.c \
				print_c.c \
				print_p.c \
				print_u.c \
				print_d.c
OBJS		= $(SRCS:%.c=%.o)

all:		$(NAME)

%.o: %.c
			$(CC) $(CFLAG) -c $< -o $@

clean:
			rm -rf $(OBJS)
	
fclean:		clean
			rm -rf $(NAME)

re:			fclean all

# $(NAME):	$(OBJS) ${INCLUDES}
$(NAME):	$(OBJS)
			ar -crs ${NAME} ${OBJS}

.PHONY:		all clean fclean re