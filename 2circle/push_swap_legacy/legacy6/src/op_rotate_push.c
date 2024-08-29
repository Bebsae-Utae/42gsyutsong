/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:15:02 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/09 17:25:47 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rr_rarb_push(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && get_where_to_b(*b, c) > 0)
			rr(a, b, 0);
		while ((*a)->nbr != c)
			ra(a, 0);
		while (get_where_to_b(*b, c) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != c && get_where_to_a(*a, c) > 0)
			rr(a, b, 0);
		while ((*b)->nbr != c)
			rb(b, 0);
		while (get_where_to_a(*a, c) > 0)
			ra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	rrr_rrarrb_push(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && get_where_to_b(*b, c) > 0)
			rrr(a, b, 0);
		while ((*a)->nbr != c)
			rra(a, 0);
		while (get_where_to_b(*b, c) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != c && get_where_to_a(*a, c) > 0)
			rrr(a, b, 0);
		while ((*b)->nbr != c)
			rrb(b, 0);
		while (get_where_to_a(*a, c) > 0)
			rra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	rra_rarb_push(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			rra(a, 0);
		while (get_where_to_b(*b, c) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (get_where_to_a(*a, c) > 0)
			rra(a, 0);
		while ((*b)->nbr != c)
			rb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	ra_rrb_push(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			ra(a, 0);
		while (get_where_to_b(*b, c) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (get_where_to_a(*a, c) > 0)
			ra(a, 0);
		while ((*b)->nbr != c)
			rrb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}