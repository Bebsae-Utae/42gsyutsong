/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:33:02 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/02 17:54:46 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (list_size(*stack_a) <= 5)
		sort_simple(stack_a, stack_b);
	else
		sort_radix(stack_a, stack_b);
}

void	sort_simple(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || list_size(*stack_a) == 0
		|| list_size(*stack_a) == 1)
		return ;
	size = list_size(*stack_a);
}

void	sort_radix(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		idx1;
	int		idx2;
	int		size;
	int		max_bits;

	idx1 = 0;
	head_a = *stack_a;
	size = list_size(head_a);
	max_bits = get_max_bits(stack_a);
	while (idx1 < max_bits)
	{
		idx2 = 0;
		while (idx2 ++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> idx1) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (list_size(*stack_b) != 0)
			pa(stack_a, stack_b);
		idx1 ++;
	}
}