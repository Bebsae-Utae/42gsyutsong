/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:16:18 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/11 15:50:48 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	inttemp;

	i = 0;
	minus = 1;
	inttemp = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i ++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			minus *= -1;
		i ++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		inttemp = inttemp * 10 + (str[i] - 48);
		i ++;
	}
	return (inttemp * minus);
}
