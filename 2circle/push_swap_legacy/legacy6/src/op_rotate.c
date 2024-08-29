/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:28:33 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/09 14:36:19 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **a, int j)
{
	t_stack *temp;
	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = temp;
	*a = temp->next;
	temp->next = NULL;
	if (j == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int j)
{
	t_stack *temp;

	if (!*b || !(*b)->next)
		return ;
	temp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = temp;
	*b = temp->next;
	temp->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int j)
{
	t_stack	*temp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	temp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = temp;
	*a = temp->next;
	temp->next = NULL;
	temp = *b;
	*b = ft_lstlast(*a);
	(*b)->next = temp;
	*b = temp->next;
	temp->next = NULL;
	if (j == 0)
		write(1, "rr\n", 3);
}