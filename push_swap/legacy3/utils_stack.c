/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:46:30 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/05 20:13:37 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		idx;

	idx = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		idx = 1;
		args = argv;
	}
	while (args[idx])
	{
		new = list_new(ft_atol(args[idx]));
		list_add_back(stack, new);
		idx ++;
	}
	stack_index(stack);
	if (argc == 2)
		free_all(args);
}

void	stack_index(t_list **stack)
{
	t_list	*head;
	int		idx;

	idx = 0;
	head = get_next_min(stack);
	while(head)
	{
		head->index = idx ++;
		head = get_next_min(stack);
	}
}
