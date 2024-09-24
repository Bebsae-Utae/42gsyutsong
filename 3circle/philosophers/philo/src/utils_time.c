/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:57:27 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/24 20:08:11 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	time_get(void)
{
	struct timeval	now;
	unsigned long	time;

	if (gettimeofday(&now, NULL) != 0)
	{
		printf("Error in ft_gettime\n");
		return (-1);
	}
	time = ((now.tv_sec * 1000) + (now.tv_usec / 1000));
	return (time);
}

void	time_sleep(t_philo **philo, long long msec)
{
	long long	timestamp;

	timestamp = time_get();
	while (!check_died(philo) && !check_dining(philo)
		&& time_get() - timestamp < msec)
		usleep(150);
}
