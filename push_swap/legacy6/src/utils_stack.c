/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:47:04 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/09 15:48:27 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_init(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		print_error();
	new->nbr = num;
	new->next = NULL;
	return (new);
}