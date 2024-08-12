/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_compact_case.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:55:28 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/12 22:38:34 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	case_rarb(t_stack *a, t_stack *b, int c, int code)
{
	int	i;

	if (code == 1)
	{
		i = get_index_of_b(b, c);
		if (i < get_index(a, c))
			i = get_index(a, c);
	}
	else if (code == 2)
	{
		i = get_index_of_a(a, c);
		if (i < get_index(b, c))
			i = get_index(b, c);
	}
	return (i);
}

int	case_rrarrb(t_stack *a, t_stack *b, int c, int code)
{
	int	i;

	i = 0;
	if (code == 1)
	{
		if (get_index_of_b(b, c))
			i = ft_lstsize(b) - get_index_of_b(b, c);
		if ((i < (ft_lstsize(a) - get_index(a, c))) && get_index(a, c))
			i = ft_lstsize(a) - get_index(a, c);
	}
	else if (code == 2)
	{
		if (get_index_of_a(a, c))
			i = ft_lstsize(a) - get_index_of_a(a, c);
		if ((i < (ft_lstsize(b) - get_index(b, c))) && get_index(b, c))
			i = ft_lstsize(b) - get_index(b, c);
	}
	return (i);
}

int	case_rrarb(t_stack *a, t_stack *b, int c, int code)
{
	int	i;

	i = 0;
	if (code == 1)
	{
		if (get_index(a, c))
			i = ft_lstsize(a) - get_index(a, c);
		i = get_index_of_b(b, c) + i;
	}
	else if (code == 2)
	{
		if (get_index_of_a(a, c))
			i = ft_lstsize(a) - get_index_of_a(a, c);
		i = get_index(b, c) + i;
	}
	return (i);
}

int	case_rarrb(t_stack *a, t_stack *b, int c, int code)
{
	int	i;

	i = 0;
	if (code == 1)
	{
		if (get_index_of_b(b, c))
			i = ft_lstsize(b) - get_index_of_b(b, c);
		i = get_index(a, c) + i;
	}
	else if (code == 2)
	{
		if (get_index(b, c))
			i = ft_lstsize(b) - get_index(b, c);
		i = get_index_of_a(a, c) + i;
	}
	return (i);
}
