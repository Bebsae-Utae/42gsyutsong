/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rotate_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:16:29 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/24 15:50:41 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_reverse(t_node **stack)
{
	t_node	*head;
	t_node	*tail;
	t_stack	*stacker;

	if (stacker->size < 2)
		return (-1);
	head = *stack;
	tail = list_size(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

void	rra(t_node **stack_a)
{
	if (rotate_reverse(stack_a) == -1)
		return (-1);
	write(1, "rra", 3);
}

void	rrb(t_node **stack_b)
{
	if (rotate_reverse(stack_b) == -1)
		return (-1);
	write(1, "rrb", 3);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	if ((list_size(*stack_a)) < 2 || (list_size(*stack_b)) < 2)
		return (-1);
	rotate_reverse(stack_a);
	rotate_reverse(stack_b);
	write(1, "rrr", 3);
}
