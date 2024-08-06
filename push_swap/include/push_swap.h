/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:14:02 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/06 21:21:16 by yutsong          ###   ########.fr       */
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

long	ft_atol(char *str);

int	is_space(int c);
int	ft_isdigit(int c);

#endif