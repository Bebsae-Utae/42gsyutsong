/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:05:37 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/08 20:09:08 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack **a, t_stack **b, int j)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = temp;
	if (j == 0)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int j)
{
	t_stack *temp;

	if (!*a)
		return ;
	temp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = temp;
	if (j == 0)
		write(1, "pb\n", 3);
}