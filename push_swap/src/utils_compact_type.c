/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_compact_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:03:15 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/12 14:38:01 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rotate_type_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = case_rrarrb_ba(a, b, b->nbr);
	while (tmp)
	{
		if (i > case_rarb_ba(a, b, tmp->nbr))
			i = case_rarb_ba(a, b, tmp->nbr);
		if (i > case_rrarrb_ba(a, b, tmp->nbr))
			i = case_rrarrb_ba(a, b, tmp->nbr);
		if (i > case_rarrb_ba(a, b, tmp->nbr))
			i = case_rarrb_ba(a, b, tmp->nbr);
		if (i > case_rrarb_ba(a, b, tmp->nbr))
			i = case_rrarb_ba(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

int	rotate_type_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = case_rrarrb_ab(a, b, a->nbr);
	while (tmp)
	{
		if (i > case_rarb_ab(a, b, tmp->nbr))
			i = case_rarb_ab(a, b, tmp->nbr);
		if (i > case_rrarrb_ab(a, b, tmp->nbr))
			i = case_rrarrb_ab(a, b, tmp->nbr);
		if (i > case_rarrb_ab(a, b, tmp->nbr))
			i = case_rarrb_ab(a, b, tmp->nbr);
		if (i > case_rrarb_ab(a, b, tmp->nbr))
			i = case_rrarb_ab(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
