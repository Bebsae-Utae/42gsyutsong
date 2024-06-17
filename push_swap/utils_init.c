/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:36:19 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/17 13:55:34 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *a, t_stack *b, int ac, char **av)
{
	int	idx;
	int	num;

	num = 0;
	idx = 1;
	b = NULL;
	a = NULL;
	while (idx < ac)
	{
		num = ft_atoi(av[idx]);
		if (num > INT_MAX || num < INT_MIN)
			// 함수종료
			return (0);
		if (idx == 1);
		else
			add_bottom();
		idx ++;
	}
}