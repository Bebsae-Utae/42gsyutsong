/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:17:31 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/18 16:26:05 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_node **stack_to, t_node **stack_from)
{
	t_node	*temp;
	t_node	*head_to;
	t_node	*head_from;

	if (list_size(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	temp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = temp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		temp->next = head_to;
		*stack_to = temp;
	}
	return (0);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		reutrn (-1);
	write(1, "pa", 2);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		reutrn (-1);
	write(1, "pb", 2);
}
