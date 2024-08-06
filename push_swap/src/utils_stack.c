/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:46:30 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/06 21:19:48 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_init(t_stack **stack_a, char **argv)
{
    long    num;
    int     idx;

	idx = 0;
	while (argv[idx])
	{
		if (check_args(argv[idx]))
			print_error(stack_a);
		num = ft_atol(argv[idx]);
		if (num > INT_MAX || num < INT_MIN)
			print_error(stack_a);
		if (check_equal(*stack_a, (int) num))
			print_error(stack_a);
		stack_append(stack_a, (int)num);
		idx ++;
	}
}

void	stack_append(t_stack **stack_a, int num)
{
	t_stack *node_now;
	t_stack *node_last;

	if (!stack_a)
		return ;
	node_now = malloc(sizeof(t_stack));
	if (!node_now)
		return ;
	node_now->next = NULL;
	node_now->count_sort = num;
	if (!(*stack_a))
	{
		*stack_a = node_now;
		node_now->prev = NULL;
	}
	else
	{
		node_last = find_last(*stack_a);
		node_last->next = node_now;
		node_now->prev = node_last;
	}
}
