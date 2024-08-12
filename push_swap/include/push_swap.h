/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:05:48 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/12 20:30:10 by yutsong          ###   ########.fr       */
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

typedef struct s_check
{
	char	**temp;
}	t_check;

void		free_list(t_stack **lst);
void		free_str(char **lst);

void		print_error(void);

void		exit_btn(void);

char		**ft_split(char const *s, char c);

size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
long		ft_atoll(const char *str);

int			ft_isdigit(int c);
int			is_equal(t_stack *a);
int			is_sorted(t_stack *a);

t_stack		*stack_init(int content);
void		stack_add_last(t_stack **stack, t_stack *stack_new);

int			get_index(t_stack *a, int nbr);
int			get_index_of_a(t_stack *stack_a, int nbr_push);
int			get_index_of_b(t_stack *stack_b, int nbr_push);
int			get_max(t_stack *a);
int			get_min(t_stack *a);

t_stack		*ft_lstlast(t_stack *lst);
int			ft_lstsize(t_stack *lst);

void		rra(t_stack **a, int code);
void		rrb(t_stack **b, int code);
void		rrr(t_stack **a, t_stack **b);

void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);

void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **stack_a, t_stack **stack_b);

void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

void		sort_3(t_stack **stack_a);
t_stack		**sort_a(t_stack **stack_a, t_stack **stack_b);
t_stack		*sort_b(t_stack **stack_a);
void		sort_big(t_stack **stack_a);
void		sort_big_to_3(t_stack **stack_a, t_stack **stack_b);

t_stack		*parse_args(int argc, char **argv);
t_stack		*parse_check(char **argv);

int			compact_rarb(t_stack **a, t_stack **b, int c, char s);
int			compact_rrarrb(t_stack **a, t_stack **b, int c, char s);
int			compact_rrarb(t_stack **a, t_stack **b, int c, char s);
int			compact_rarrb(t_stack **a, t_stack **b, int c, char s);

int			case_rarb(t_stack *a, t_stack *b, int c, int code);
int			case_rrarrb(t_stack *a, t_stack *b, int c, int code);
int			case_rrarb(t_stack *a, t_stack *b, int c, int code);
int			case_rarrb(t_stack *a, t_stack *b, int c, int code);

int			rotate_type_ba(t_stack *a, t_stack *b);
int			rotate_type_ab(t_stack *a, t_stack *b);

#endif