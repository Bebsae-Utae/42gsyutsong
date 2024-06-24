/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:05:50 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/24 15:43:54 by yutsong          ###   ########.fr       */
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

void	command(t_node **stack_a, t_node **stack_b);

int		push(t_node **stack_to, t_node **stack_from);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);

int		rotate_reverse(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

int		rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);

int		swap(t_node **stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

void	check_args(int argc, char **argv);
int		check_num(char *num);
int		check_duplicate(int num, char **argv, int idx);
int		check_sorted(t_node **stack);

int		ft_atoi(char	*str);
t_node	*ft_lstnew(void *content);

void	init_stack(t_node **stack, int argc, char **argv);

t_node	*list_make_new(int value);
t_node	*list_return_last(t_node *head);
void	list_add_front(t_node **stack, t_node *new);
void	list_add_back(t_node **stack, t_node *new);
void	list_get_size(t_node *head, t_stack *stack_manager);
void	list_free(char **str);

void	print_error();
void	print_list(t_node *head);

void	sort_stack(t_node **stack_a, t_node **stack_b, t_stack *stack_manager_a);
void	sort_simple(t_node **stack_a, t_node **stack_b);

void	stack_push_args(char **argv);
t_node	*stack_next_stack(t_node **stack);
void	stack_index(t_node **stack);
void	stack_free(t_node **stack);

#endif
