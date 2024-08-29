/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_ba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:02:16 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/09 18:05:04 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	case_ba_rarb(t_stack *a, t_stack *b, int c)
{
	int	idx;

	idx = get_where_to_a(a, c);
	if (idx < get_index(b, c))
		idx = get_index(b, c);
	return (idx);
}

int	case_ba_rrarrb(t_stack *a, t_stack *b, int c)
{
	int	idx;

	idx = 0;
	if (get_where_to_a(a, c))
		idx = ft_lstsize(a) - get_where_to_a(a,c);
	if ((idx < (ft_lstsize(b) - get_index(b, c))) && get_index(b, c))
		idx = ft_lstsize(b) - get_index(b, c);
	return (idx);
}

int	case_ba_rarrb(t_stack *a, t_stack *b, int c)
{
	int	idx;
	
	idx = 0;
	if (get_index(b, c))
		idx = ft_lstsize(b) - get_index(b, c);
	idx = get_where_to_a(a, c) + idx;
	return (idx);
}

int	case_ba_rrarb(t_stack *a, t_stack *b, int c)
{
	int	idx;

	idx = 0;
	if (get_where_to_a(a, c))
		idx = ft_lstsize(a) - get_where_to_a(a, c);
	idx = get_index(b, c) + idx;
	return (idx);
}
