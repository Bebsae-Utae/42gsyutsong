/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_compact_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:03:15 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/12 16:14:31 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rotate_type_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = case_rrarrb(a, b, b->nbr, 2);
	while (tmp)
	{
		if (i > case_rarb(a, b, tmp->nbr, 2))
			i = case_rarb(a, b, tmp->nbr, 2);
		if (i > case_rrarrb(a, b, tmp->nbr, 2))
			i = case_rrarrb(a, b, tmp->nbr, 2);
		if (i > case_rarrb(a, b, tmp->nbr, 2))
			i = case_rarrb(a, b, tmp->nbr, 2);
		if (i > case_rrarb(a, b, tmp->nbr, 2))
			i = case_rrarb(a, b, tmp->nbr, 2);
		tmp = tmp->next;
	}
	return (i);
}

int	rotate_type_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = case_rrarrb(a, b, a->nbr, 1);
	while (tmp)
	{
		if (i > case_rarb(a, b, tmp->nbr, 1))
			i = case_rarb(a, b, tmp->nbr, 1);
		if (i > case_rrarrb(a, b, tmp->nbr, 1))
			i = case_rrarrb(a, b, tmp->nbr, 1);
		if (i > case_rarrb(a, b, tmp->nbr, 1))
			i = case_rarrb(a, b, tmp->nbr, 1);
		if (i > case_rrarb(a, b, tmp->nbr, 1))
			i = case_rrarb(a, b, tmp->nbr, 1);
		tmp = tmp->next;
	}
	return (i);
}
