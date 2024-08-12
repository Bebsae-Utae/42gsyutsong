/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:17:06 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/12 14:46:17 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_3(t_stack **stack_a)
{
	if (get_min(*stack_a) == (*stack_a)->nbr)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (get_max(*stack_a) == (*stack_a)->nbr)
	{
		ra(stack_a);
		if (!is_sorted(*stack_a))
			sa(stack_a);
	}
	else
	{
		if (get_index(*stack_a, get_max(*stack_a)) == 1)
			rra(stack_a);
		else
			sa(stack_a);
	}
}

void	sort_big_to_3(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (ft_lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
	{
		tmp = *stack_a;
		i = rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb_ab(*stack_a, *stack_b, tmp->nbr))
				i = compact_rarb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == case_rrarrb_ab(*stack_a, *stack_b, tmp->nbr))
				i = compact_rrarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == case_rarrb_ab(*stack_a, *stack_b, tmp->nbr))
				i = compact_rarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == case_rrarb_ab(*stack_a, *stack_b, tmp->nbr))
				i = compact_rrarb(stack_a, stack_b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_stack	*sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		pb(stack_a, &stack_b);
	if (ft_lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		pb(stack_a, &stack_b);
	if (ft_lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		sort_big_to_3(stack_a, &stack_b);
	if (!is_sorted(*stack_a))
		sort_3(stack_a);
	return (stack_b);
}

t_stack	**sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb_ba(*stack_a, *stack_b, tmp->nbr))
				i = compact_rarb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == case_rarrb_ba(*stack_a, *stack_b, tmp->nbr))
				i = compact_rarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == case_rrarrb_ba(*stack_a, *stack_b, tmp->nbr))
				i = compact_rrarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == case_rrarb_ba(*stack_a, *stack_b, tmp->nbr))
				i = compact_rrarb(stack_a, stack_b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

void	sort_big(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else
	{
		stack_b = sort_b(stack_a);
		stack_a = sort_a(stack_a, &stack_b);
		i = get_index(*stack_a, get_min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->nbr != get_min(*stack_a))
				ra(stack_a);
		}
		else
		{
			while ((*stack_a)->nbr != get_min(*stack_a))
				rra(stack_a);
		}			
	}	
}
