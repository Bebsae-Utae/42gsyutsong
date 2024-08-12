/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:08:35 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/09 18:13:09 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_ba(t_stack *a, t_stack *b)
{
	int		idx;
	t_stack	*temp;

	temp = b;
	idx = case_ba_rrarrb(a, b, b->nbr);
	while (temp)
	{
		if (idx > case_ba_rarb(a, b, temp->nbr))
			idx = case_ba_rarb(a, b, temp->nbr);
		if (idx > case_ba_rrarrb(a, b, temp->nbr))
			idx = case_ba_rrarrb(a, b, temp->nbr);
		if (idx > case_ba_rarrb(a, b, temp->nbr))
			idx = case_ba_rarrb(a, b, temp->nbr);
		if (idx > case_ba_rrarb(a, b, temp->nbr))
			idx = case_ba_rrarb(a, b, temp->nbr);
		temp = temp->next;
	}
	return (idx);
}

int	check_ab(t_stack *a, t_stack *b)
{
	int		idx;
	t_stack	*temp;

	temp = b;
	idx = case_ab_rrarrb(a, b, b->nbr);
	while (temp)
	{
		if (idx > case_ab_rarb(a, b, temp->nbr))
			idx = case_ab_rarb(a, b, temp->nbr);
		if (idx > case_ab_rrarrb(a, b, temp->nbr))
			idx = case_ab_rrarrb(a, b, temp->nbr);
		if (idx > case_ab_rarrb(a, b, temp->nbr))
			idx = case_ab_rarrb(a, b, temp->nbr);
		if (idx > case_ab_rrarb(a, b, temp->nbr))
			idx = case_ab_rrarb(a, b, temp->nbr);
		temp = temp->next;
	}
	return (idx);
}