/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:14:02 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/02 17:57:40 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

void	check_args(int argc, char **argv);
int		check_equal(int num, char **argv, int i);

int		print_error(int code);

void	free_all(char **str);
void	free_stack(t_list **stack);

int		get_max_bits(t_list **stack);
t_list	*get_next_min(t_list **stack);

int		ft_isnum(char *num);
int		ft_isdigit(int c);
int		is_sorted(t_list **stack);

t_list	*list_new(int value);
t_list	*list_last(t_list *head);
t_list	list_add_back(t_list **stack, t_list *new);
int		list_size(t_list *head);

void	ft_putstr_fd(char *s, int fd);

void	sort_stack(t_list **stack_a, t_list **stack_b);

char	**ft_split(char const *s, char c);

void	stack_init(t_list **stack, int argc, char **argv);
void	stack_index(t_list **stack);

int		ft_atoi(char *str);

#endif