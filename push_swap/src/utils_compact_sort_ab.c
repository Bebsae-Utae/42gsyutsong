/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_compact_sort_ab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:47:55 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/10 21:04:25 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	compact_rarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && get_index_of_b(*b, c) > 0)
			rr(a, b, 0);
		while ((*a)->nbr != c)
			ra(a, 0);
		while (get_index_of_b(*b, c) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != c && get_index_of_a(*a, c) > 0)
			rr(a, b, 0);
		while ((*b)->nbr != c)
			rb(b, 0);
		while (get_index_of_a(*a, c) > 0)
			ra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	compact_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && get_index_of_b(*b, c) > 0)
			rrr(a, b, 0);
		while ((*a)->nbr != c)
			rra(a, 0);
		while (get_index_of_b(*b, c) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != c && get_index_of_a(*a, c) > 0)
			rrr(a, b, 0);
		while ((*b)->nbr != c)
			rrb(b, 0);
		while (get_index_of_a(*a, c) > 0)
			rra(a, 0);
		pa(a, b, 0);
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
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (get_index_of_a(*a, c) > 0)
			rra(a, 0);
		while ((*b)->nbr != c)
			rb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	compact_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			ra(a, 0);
		while (get_index_of_b(*b, c) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (get_index_of_a(*a, c) > 0)
			ra(a, 0);
		while ((*b)->nbr != c)
			rrb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}

