/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:56:08 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/09 18:06:43 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	case_ab_rarb(t_stack *a, t_stack *b, int c)
{
	int	idx;

	idx = get_where_to_b(b, c);
	if (idx < get_index(a, c))
		idx = get_index(a, c);
	return (idx);
}

int	case_ab_rrarrb(t_stack *a, t_stack *b, int c)
{
	int	idx;

	idx = 0;
	if (get_where_to_b(b, c))
		idx = ft_lstsize(b) - get_where_to_b(b,c);
	if ((idx < (ft_lstsize(a) - get_index(a, c))) && get_index(a, c))
		idx = ft_lstsize(a) - get_index(a, c);
	return (idx);
}

int	case_ab_rrarb(t_stack *a, t_stack *b, int c)
{
	int	idx;
	
	idx = 0;
	if (get_index(a, c))
		idx = ft_lstsize(a) - get_index(a, c);
	idx = get_where_to_b(b, c) + idx;
	return (idx);
}

int	case_ab_rarrb(t_stack *a, t_stack *b, int c)
{
	int	idx;

	idx = 0;
	if (get_where_to_b(b, c))
		idx = ft_lstsize(b) - get_where_to_b(b, c);
	idx = get_index(a, c) + idx;
	return (idx);
}