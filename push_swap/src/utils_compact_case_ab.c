/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_compact_case.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:55:28 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/10 20:58:04 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	case_rarb_ab(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = get_index_of_b(b, c);
	if (i < get_index(a, c))
		i = get_index(a, c);
	return (i);
}

int	case_rrarrb_ab(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (get_index_of_b(b, c))
		i = ft_lstsize(b) - get_index_of_b(b, c);
	if ((i < (ft_lstsize(a) - get_index(a, c))) && get_index(a, c))
		i = ft_lstsize(a) - get_index(a, c);
	return (i);
}

int	case_rrarb_ab(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (get_index(a, c))
		i = ft_lstsize(a) - get_index(a, c);
	i = get_index_of_b(b, c) + i;
	return (i);
}

int	case_rarrb_ab(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (get_index_of_b(b, c))
		i = ft_lstsize(b) - get_index_of_b(b, c);
	i = get_index(a, c) + i;
	return (i);
}

