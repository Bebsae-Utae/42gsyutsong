/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:15:33 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/18 16:32:48 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_node **stack)
{
	t_node	*head;
	t_node	*next;
	int		temp_value;
	int		temp_index;

	if (list_size(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		print_error();
	temp_value = head->value;
	temp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = temp_value;
	next->index = temp_index;
	return (0);
}

void	sa(t_node **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	write(1, "sa", 2);
}

void	sb(t_node **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	write(1, "sb", 2);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	if ((list_size(*stack_a)) < 2 || (list_size(*stack_b)) <2)
		return (-1);
	swap(stack_a);
	swap(stack_b);
	write(1, "ss", 2);
}
