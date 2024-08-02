/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:25:53 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/02 17:55:20 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	idx;
	int	minus;
	int	result;

	idx = 0;
	minus = 1;
	result = 0;
	while (str[idx] >= 7 && str[idx] <= 13)
		idx ++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
		 	minus *= -1;
		idx ++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		result *= 10;
		result += str[idx] - '0';
		idx ++;
	}
	return (result * minus);
}
