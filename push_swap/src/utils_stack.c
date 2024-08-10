/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:14:38 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/10 20:00:17 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*stack_init(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		print_error();
	new->nbr = content;
	new->next = NULL;
	return (new);
}

void	stack_add_args(char **argv, t_stack **stack_a)
{
	long	i;

	i = 1;
	while (argv[i] != NULL)
	{
		stack_add_last(stack_a, stack_init(ft_atoi(argv[i])));
		i++;
	}
}

void	stack_add_last(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_lstlast(*stack))->next = stack_new;
}
