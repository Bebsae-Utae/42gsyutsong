/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:36:35 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/09 15:32:02 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **a, int j)
{
	int		idx;
	t_stack	*temp;

	if (!*a || !(*a)->next)
		return ;
	idx = 0;
	temp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		idx ++;
	}
	(*a)->next = temp;
	while (idx > 1)
	{
		temp = temp->next;
		idx --;
	}
	temp->next = NULL;
	if (j == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int j)
{
	int		idx;
	t_stack	*temp;

	if (!*b || !(*b)->next)
		return ;
	idx = 0;
	temp = *b;
	while ((*b)->next)
	{
		*b = (*b)->next;
		idx ++;
	}
	(*b)->next = temp;
	while (idx > 1)
	{
		temp = temp->next;
		idx --;
	}
	temp->next = NULL;
	if (j == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int j)
{
	int		idx;
	t_stack	*temp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	idx = 0;
	temp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		idx ++;
	}
	(*a)->next = temp;
	while (idx > 1)
	{
		temp = temp->next;
		idx --;
	}
	temp->next = NULL;
	idx = 0;
	temp = *b;
	while ((*b)->next)
	{
		*b = (*b)->next;
		idx ++;
	}
	(*b)->next = temp;
	while (idx > 1)
	{
		temp = temp->next;
		idx --;
	}
	temp->next = NULL;
	if (j == 0)
		write(1, "rrr\n", 4);
}
