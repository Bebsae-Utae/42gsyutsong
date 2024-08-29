/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:32:51 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/09 15:41:34 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min(t_stack *stack)
{
	int	idx;

	idx = stack->nbr;
	while (stack)
	{
		if (stack->nbr < idx)
			idx = stack->nbr;
		stack = stack->next;
	}
	return (idx);
}

int	get_max(t_stack *stack)
{
	int	idx;

	idx = stack->nbr;
	while (stack)
	{
		if (stack->nbr > idx)
			idx = stack->nbr;
		stack = stack->next;
	}
	return (idx);
}

int	get_index(t_stack *stack, int nbr)
{
	int	idx;

	idx = 0;
	while (stack->nbr != nbr)
	{
		idx ++;
		stack = stack->next;
	}
	stack->index = 0;
	return (idx);
}

int	get_where_to_b(t_stack *b, int nbr_push)
{
	int		idx;
	t_stack	*temp;

	idx = 1;
	if (nbr_push > b->nbr && nbr_push < ft_lstlast(b)->nbr)
		idx = 0;
	else if (nbr_push > get_max(b) || nbr_push < get_min(b))
		idx = get_index(b, get_max(b));
	else
	{
		temp = b->next;
		while (b->nbr < nbr_push || temp->nbr > nbr_push)
		{
			b = b->next;
			temp = b->next;
			idx ++;
		}
	}
	return (idx);
}

int	get_where_to_a(t_stack *a, int nbr_push)
{
	int		idx;
	t_stack	*temp;

	idx = 1;
	if (nbr_push < a->nbr && nbr_push > ft_lstlast(a)->nbr)
		idx = 0;
	else if (nbr_push > get_max(a) || nbr_push < get_min(a))
		idx = get_index(a, get_min(a));
	else
	{
		temp = a->next;
		while (a->nbr > nbr_push || temp->nbr < nbr_push)
		{
			a = a->next;
			temp = a->next;
			idx ++;
		}
	}
	return (idx);
}