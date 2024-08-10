/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:30:36 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/10 18:08:55 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
	{
		lst = lst -> next;
	}
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		count ++;
	}
	return (count);
}

void	list_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_lstlast(*stack))->next = stack_new;
}

void	list_add_args(char **argv, t_stack **a)
{
	long	idx;

	idx = 1;
	while (argv[idx] != NULL)
	{
		list_add_back(a, stack_init(ft_atoll(argv[idx])));
		idx ++;
	}
}