/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:04:36 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/10 17:21:53 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_stack **a)
{
	if (get_min(*a) == (*a)->nbr)
	{
		rra(a, 0);
		sa(a, 0);
	}
	else if (get_max(*a) == (*a)->nbr)
	{
		ra(a, 0);
		if (!is_sorted(*a))
			sa(a, 0);
	}
	else
	{
		if (get_index(*a, get_max(*a)) == 1)
			rra(a, 0);
		else
			sa(a, 0);
	}
}

void	sort_to_3(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*temp;

	while (ft_lstsize(*a) > 3 && !is_sorted(*a))
	{
		temp = *a;
		i = check_ab(*a, *b);
		while (i >= 0)
		{
			if (i == case_ab_rarb(*a, *b, temp->nbr))
				i = rr_rarb_push(a, b, temp->nbr, 'a');
			else if (i == case_ab_rrarrb(*a, *b, temp->nbr))
				i = rrr_rrarrb_push(a, b, temp->nbr, 'a');
			else if (i == case_ab_rarrb(*a, *b, temp->nbr))
				i = ra_rrb_push(a, b, temp->nbr, 'a');
			else if (i == case_ab_rrarb(*a, *b, temp->nbr))
				i = rra_rarb_push(a, b, temp->nbr, 'a');
			else
				temp = temp->next;
		}
	}
}

t_stack	*sort_b(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (ft_lstsize(*a) > 3 && !is_sorted(*a))
		pb(a, &b, 0);
	if (ft_lstsize(*a) > 3 && !is_sorted(*a))
		pb(a, &b, 0);
	if (ft_lstsize(*a) > 3 && !is_sorted(*a))
		sort_to_3(a, &b);
	if (!is_sorted(*a))
		sort_3(a);
	return (b);
}

t_stack	**sort_a(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*temp;

	while (*b)
	{
		temp = *b;
		i = check_ba(*a, *b);
		while (i >= 0)
		{
			if (i == case_ba_rarb(*a, *b, temp->nbr))
				i = rr_rarb_push(a, b, temp->nbr, 'b');
			else if (i == case_ba_rarrb(*a, *b, temp->nbr))
				i = ra_rrb_push(a, b, temp->nbr, 'b');
			else if (i == case_ba_rrarrb(*a, *b, temp->nbr))
				i = rrr_rrarrb_push(a, b, temp->nbr, 'b');
			else if (i == case_ba_rrarb(*a, *b, temp->nbr))
				i = rra_rarb_push(a, b, temp->nbr, 'b');
			else
				temp = temp->next;
		}
	}
	return (a);
}

void	sort_back(t_stack **a)
{
	t_stack	*b;
	int		i;

	b = NULL;
	if (ft_lstsize(*a) == 2)
		sa(a, 0);
	else
	{
		b = sort_b(a);
		a = sort_a(a, &b);
		i = get_index(*a, get_min(*a));
		if (i < ft_lstsize(*a) - i)
			while ((*a)->nbr != get_min(*a))
				ra(a, 0);
		else
			while ((*a)->nbr != get_min(*a))
				rra(a, 0);
	}	
}
