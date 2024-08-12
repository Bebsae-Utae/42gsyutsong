/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_compact_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:47:55 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/12 16:30:55 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	compact_rarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && get_index_of_b(*b, c) > 0)
			rr(a, b);
		while ((*a)->nbr != c)
			ra(a);
		while (get_index_of_b(*b, c) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while ((*b)->nbr != c && get_index_of_a(*a, c) > 0)
			rr(a, b);
		while ((*b)->nbr != c)
			rb(b);
		while (get_index_of_a(*a, c) > 0)
			ra(a);
		pa(a, b);
	}
	return (-1);
}

int	compact_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && get_index_of_b(*b, c) > 0)
			rrr(a, b);
		while ((*a)->nbr != c)
			rra(a, 0);
		while (get_index_of_b(*b, c) > 0)
			rrb(b, 0);
		pb(a, b);
	}
	else
	{
		while ((*b)->nbr != c && get_index_of_a(*a, c) > 0)
			rrr(a, b);
		while ((*b)->nbr != c)
			rrb(b, 0);
		while (get_index_of_a(*a, c) > 0)
			rra(a, 0);
		pa(a, b);
	}
	return (-1);
}

int	compact_rrarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			rra(a, 0);
		while (get_index_of_b(*b, c) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while (get_index_of_a(*a, c) > 0)
			rra(a, 0);
		while ((*b)->nbr != c)
			rb(b);
		pa(a, b);
	}
	return (-1);
}

int	compact_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			ra(a);
		while (get_index_of_b(*b, c) > 0)
			rrb(b, 0);
		pb(a, b);
	}
	else
	{
		while (get_index_of_a(*a, c) > 0)
			ra(a);
		while ((*b)->nbr != c)
			rrb(b, 0);
		pa(a, b);
	}
	return (-1);
}
