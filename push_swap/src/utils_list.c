/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:53:33 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/02 17:35:17 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*list_new(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if(!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_list	*list_last(t_list *head)
{
	t_list	*temp;

	temp = head;
	while(temp->next)
	{
		temp = temp->next;
		if(temp->next == NULL)
			return (temp);
	}
	return (temp);
}

t_list	list_add_back(t_list **stack, t_list *new)
{
	t_list	*n;

	if(*stack)
	{
		n = list_last(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

int	list_size(t_list *head)
{
	int		idx;
	t_list	*temp;

	temp = head;
	idx = 0;
	while (temp)
	{
		temp = temp->next;
		idx ++;
	}
	return (idx);
}