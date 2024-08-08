/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:14:02 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/08 16:37:26 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int count_sort;
	int idx;
	int count_cmd;
	bool above_median;
	bool cheapest;
	struct s_stack *target_node;
	struct s_stack *next;
	struct s_stack *prev;
}	t_stack;

char	**ft_split(char const *s, char c);

int	check_args(char *str);
int	check_equal(t_stack *stack_a, int num);

void	stack_init(t_stack **stack_a, char **argv);
void	stack_append(t_stack **stack_a, int num);

int	print_error(t_stack **stack_a);

void	free_stack(t_stack **stack);
void	free_all(char **str);


int	is_space(int c);
bool	is_sorted(t_stack *stack);
int	ft_isdigit(int c);

t_stack	*find_last(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);

void	sort_3(t_stack **stack_a);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
int	stack_size(t_stack *stack);

void	sa(t_stack	**a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);

void	pa(t_stack **stack_a, t_stack **stack_b, bool print);
void	pb(t_stack **stack_b, t_stack **stack_a, bool print);

void	ra(t_stack **stack_a, bool print);
void	rb(t_stack **stack_b, bool print);
void	rr(t_stack **stack_a, t_stack **stack_b, bool print);

void	rra(t_stack **stack_a, bool print);
void	rrb(t_stack **stack_b, bool print);
void	rrr(t_stack **stack_a, t_stack **stack_b, bool print);

void 	current_index(t_stack *stack);

void	set_cheapest(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);

void	init_nodes_a(t_stack *stack_a, t_stack *stack_b);
void	init_nodes_b(t_stack *stack_a, t_stack *stack_b);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);

int	ft_strlen(const char *str);
int	ft_strlcpy(char *dest, const char *src, int size);
long	ft_atol(char *str);


int	counter_word(char const *str, char c);
int	setter_word(char const *str, char c, char **result, int idx);

#endif