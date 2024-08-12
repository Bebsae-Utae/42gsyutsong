/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_compact_case_ba.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:00:15 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/12 14:28:56 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	case_rarb_ba(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = get_index_of_a(a, c);
	if (i < get_index(b, c))
		i = get_index(b, c);
	return (i);
}

int	case_rrarrb_ba(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (get_index_of_a(a, c))
		i = ft_lstsize(a) - get_index_of_a(a, c);
	if ((i < (ft_lstsize(b) - get_index(b, c))) && get_index(b, c))
		i = ft_lstsize(b) - get_index(b, c);
	return (i);
}

int	case_rrarb_ba(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (get_index_of_a(a, c))
		i = ft_lstsize(a) - get_index_of_a(a, c);
	i = get_index(b, c) + i;
	return (i);
}

int	case_rarrb_ba(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (get_index(b, c))
		i = ft_lstsize(b) - get_index(b, c);
	i = get_index_of_a(a, c) + i;
	return (i);
}
