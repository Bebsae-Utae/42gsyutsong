/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:05:50 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/18 17:30:03 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

void	check_args(int argc, char **argv);
int		check_num(char *num);
int		check_duplicate(int num, char **argv, int idx);
int		check_sorted(t_node **stack);

void	print_error();

void	init_stack(t_node **stack, int argc, char **argv);

int		ft_atoi(char	*str);
t_node	*ft_lstnew(void *content);

#endif
