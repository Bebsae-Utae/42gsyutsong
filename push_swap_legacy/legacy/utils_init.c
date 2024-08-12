/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:36:19 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/18 17:20:54 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_node **stack, int argc, char **argv)
{
	t_node	*new;
	int		idx;

	idx = 1;
	while (argv[idx])
	{
		new = ft_lstnew(ft_atoi(argv[idx]));
		list_add_back(stack, new);
		idx ++;
	}
	stack_index(stack);
	if (argc == 2)
		list_free(argv);
}