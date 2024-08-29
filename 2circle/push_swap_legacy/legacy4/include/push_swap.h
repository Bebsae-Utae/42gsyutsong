/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:14:02 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/08 16:15:09 by yutsong          ###   ########.fr       */
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
int		check_equal(long num, char **argv, int i);

int		print_error(int code);

void	free_all(char **str);
void	free_stack(t_list **stack);

int		get_max_bits(t_list **stack);
t_list	*get_next_min(t_list **stack);
int		get_min(t_list **stack, int val);
int		get_distance(t_list **stack, int index);

int		ft_isnum(char *num);
int		ft_isdigit(int c);
int		is_sorted(t_list **stack);

t_list	*list_new(int value);
t_list	*list_last(t_list *head);
void	list_add_back(t_list **stack, t_list *new);
int		list_size(t_list *head);

int		push(t_list **stack_to, t_list **stack_from);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_b, t_list **stack_a);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);

int		reverse_rotate(t_list **stack);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

int		rotate(t_list **stack);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);

void	sort_stack(t_list **stack_a, t_list **stack_b);
void	sort_radix(t_list **stack_a, t_list **stack_b);
void	sort_simple(t_list **stack_a, t_list **stack_b);
void	sort_3(t_list **stack_a);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);

char	**ft_split(char const *s, char c);
int		counter_word(char const *str, char c);
int		setter_word(char const *str, char c, char **result, int idx);

void	stack_init(t_list **stack, int argc, char **argv);
void	stack_index(t_list **stack);

int		swap(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);

long	ft_atol(char *str);
int		ft_strlcpy(char *dest, const char *src, int size);
int		ft_strlen(const char *str);

#endif