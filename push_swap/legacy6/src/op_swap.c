/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:09:39 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/09 14:28:21 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **a, int j)
{
	t_stack	*temp;

	if (!*a || ((*a)->next))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	if (j == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int j)
{
	t_stack *temp;

	if (!*b || !((*b)->next))
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	if (j == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int j)
{
	t_stack	*temp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	if (j == 0)
		write(1, "ss\n", 3);
}