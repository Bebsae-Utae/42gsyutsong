/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_revrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:12:53 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/08 16:02:09 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack **stack_a, bool print)
{
	rev_rotate(stack_a);
	if (!print)
		write(1, "rra\n", 3);
}

void	rrb(t_stack **stack_b, bool print)
{
	rev_rotate(stack_b);
	if (!print)
		write(1, "rrb\n", 3);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (!print)
		write(1, "rrr\n", 3);
}