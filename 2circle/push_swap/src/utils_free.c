/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:08:34 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/13 16:29:29 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_list(t_stack **lst)
{
	t_stack	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		(*lst)->nbr = 0;
		free(*lst);
		*lst = temp;
	}
}

void	free_str(char **lst)
{
	char	*n1;

	if (!lst)
		return ;
	while (*lst)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	*lst = NULL;
}

void	freeze(char **tmp)
{
	free_str(tmp);
	free(tmp);
	print_error();
}

void	freedom(t_stack *a, char **tmp)
{
	free_str(tmp);
	free(tmp);
	free_list(&a);
	free(a);
	print_error();
}

void	freezer(char **tmp)
{
	free_str(tmp);
	free(tmp);
}
