/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:56:04 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/18 17:03:05 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push_args(char **argv)
{
	t_stack	*new;
	int		idx;

	idx = 0;
	if (new == NULL)
		return ;
	while (argv[idx])
	{
		new = ft_lstnew(ft_atoi(argv[idx]));
		
		idx ++;
	}
}

t_node	*stack_next_stack(t_node **stack)
{
	t_node	*head;
	t_node	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	stack_index(t_node **stack)
{
	t_node *head;
	int		idx;

	idx = 0;
	head = stack_next_stack(stack);
	while (head)
	{
		head->index = idx ++;
		head = stack_next_stack(stack);
	}
}

void	stack_free(t_node **stack)
{
	t_node	*head;
	t_node	*temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(stack);
}