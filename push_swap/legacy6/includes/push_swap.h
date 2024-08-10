/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:18:24 by yogun             #+#    #+#             */
/*   Updated: 2024/08/10 17:35:56 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		is_space(int c);
int		ft_isdigit(int c);
int		is_equal(t_stack *a);
int		ft_isalpha(int c);
int		is_sorted(t_stack *a);

t_stack	*parse_check(int argc, char **argv);
t_stack	*parse_args(char **argv);

int		check_args(char **argv, int i, int j);
int		check_args2(char **argv);
void	check_alpha(char **argv);
t_stack	*ft_process(int argc, char **argv);

int		ft_atoll(const char *str);

void	print_error(void);

void	freeze(t_stack **lst);
void	free_str(char **lst);
void	free_all(char **str);

char	**ft_split(char const *s, char c);
int		ft_strlcpy(char *dest, const char *src, int size);
int		ft_strlen(const char *str);
int		counter_word(char const *str, char c);
int		setter_word(char const *str, char c, char **result, int idx);

t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
void	list_add_back(t_stack **stack, t_stack *stack_new);
void	list_add_args(char **argv, t_stack **a);

void	pa(t_stack **a, t_stack **b, int j);
void	pb(t_stack **a, t_stack **b, int j);

void	sa(t_stack **a, int j);
void	sb(t_stack **b, int j);
void	ss(t_stack **a, t_stack **b, int j);

void	ra(t_stack **a, int j);
void	rb(t_stack **b, int j);
void	rr(t_stack **a, t_stack **b, int j);

void	rra(t_stack **a, int j);
void	rrb(t_stack **b, int j);
void	rrr(t_stack **a, t_stack **b, int j);

int		rr_rarb_push(t_stack **a, t_stack **b, int c, char s);
int		rrr_rrarrb_push(t_stack **a, t_stack **b, int c, char s);
int		rra_rarb_push(t_stack **a, t_stack **b, int c, char s);
int		ra_rrb_push(t_stack **a, t_stack **b, int c, char s);

int		case_ab_rarrb(t_stack *a, t_stack *b, int c);
int		case_ab_rrarb(t_stack *a, t_stack *b, int c);
int		case_ab_rrarrb(t_stack *a, t_stack *b, int c);
int		case_ab_rarb(t_stack *a, t_stack *b, int c);

int		case_ba_rarb(t_stack *a, t_stack *b, int c);
int		case_ba_rrarrb(t_stack *a, t_stack *b, int c);
int		case_ba_rarrb(t_stack *a, t_stack *b, int c);
int		case_ba_rrarb(t_stack *a, t_stack *b, int c);

int		check_ab(t_stack *a, t_stack *b);
int		check_ba(t_stack *a, t_stack *b);

int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		get_index(t_stack *stack, int nbr);
int		get_where_to_b(t_stack *b, int nbr_push);
int		get_where_to_a(t_stack *a, int nbr_push);

void	sort_3(t_stack **a);
void	sort_to_3(t_stack **a, t_stack **b);
t_stack	**sort_a(t_stack **a, t_stack **b);
t_stack	*sort_b(t_stack **a);
void	sort_back(t_stack **a);

t_stack	*stack_init(int num);

#endif