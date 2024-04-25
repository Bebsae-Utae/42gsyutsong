/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:35:34 by yutsong           #+#    #+#             */
/*   Updated: 2024/03/15 14:14:39 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*address;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		address = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = address;
	}
	*lst = 0;
}
