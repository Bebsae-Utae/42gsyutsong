/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:43:51 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/18 17:03:48 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*list_make_new(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(*new));
	if(!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_node	*list_return_last(t_node *head)
{
	t_node	*temp;

	temp = head;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->next == NULL)
			return (temp);
	}
	return (temp);
}

void	list_add_front(t_node **stack, t_node *new)
{
	new->next = *stack;
	*stack = new;
}

void	list_add_back(t_node **stack, t_node *new)
{
	t_node	*stacker;

	if (*stack)
	{
		stacker = list_add_last(*stack);
		stacker->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

void	list_get_size(t_node *head, t_stack *stack_manager)
{
	int		idx;
	t_node	*temp;

	temp = head;
	idx = 0;
	while (temp)
	{
		temp = temp->next;
		idx ++;
	}
	stack_manager->size = idx;
}

void	list_free(char **str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx ++;
	while (idx >= 0)
		free(str[idx --]);
}
