/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:19:55 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/18 16:27:58 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_node **stack)
{
	t_node	*head;
	t_node	*tail;

	if (list_size(*stack) < 2)
		return (-1);
	head = *stack;
	tail = list_add_last(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

void	ra(t_node **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	write(1, "ra", 2);
}

void	rb(t_node **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	write(1, "rb", 2);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	if ((list_size(*stack_a) < 2) || (list_size(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr", 2);
}