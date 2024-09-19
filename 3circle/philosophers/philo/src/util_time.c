/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:36:54 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/19 16:07:33 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	time_wasted(long long wait_time, t_input *input)
{
	long long	start_time;
	long long	end_time;

	start_time = time_get();
	end_time = start_time + wait_time;
	while (!input->monitor && time_get() < end_time)
		usleep(100);
}

long	time_get(void)
{
	struct timeval	current_time;
	long			result;

	if (gettimeofday(&current_time, NULL) != 0)
		return (-1);
	result = (current_time.tv_sec * 1000LL) + (current_time.tv_usec / 1000);
	return (result);
}
