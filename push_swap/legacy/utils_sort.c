/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:03:24 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/18 15:41:49 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **stack_a, t_node **stack_b, t_stack *stack_manager_a)
{
	if (stack_manager_a->size <= 5)
		sort_simple(stack_a, stack_b);
	else
		sort_radix(stack_a, stack_b);
}

void	sort_simple(t_node **stack_a, t_node **stack_b)
{
	int	size;

	if (check_sorted(stack_a) || list_size(*stack_a) == 0 || list_size(*stack_a) == 1)
		return ;
	size = list_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}