/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:44:50 by tclement          #+#    #+#             */
/*   Updated: 2024/09/24 18:41:45 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>


long int	ft_atol(char *str)
{
	long int		i;
	long int		nb;

	i = 0;
	nb = 0;
	if (str[i] == '\0' || str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0' || i > 10)
		return (-1);
	return (nb);
}
