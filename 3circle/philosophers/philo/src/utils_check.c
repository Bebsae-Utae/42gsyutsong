/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:08:58 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/24 20:09:27 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_died(t_philo **philo)
{
	pthread_mutex_lock(&(*philo)->input->mutex_died);
	if ((*philo)->input->died == 1)
	{
		pthread_mutex_unlock(&(*philo)->input->mutex_died);
		return (1);
	}
	pthread_mutex_unlock(&(*philo)->input->mutex_died);
	return (0);
}

int	check_dining(t_philo **philo)
{
	pthread_mutex_lock(&(*philo)->input->mutex_dining);
	if ((*philo)->input->done_dining == (*philo)->input->count_philo)
	{
		pthread_mutex_unlock(&(*philo)->input->mutex_dining);
		return (1);
	}
	pthread_mutex_unlock(&(*philo)->input->mutex_dining);
	return (0);
}

int	check_time_dining(t_philo **philo, int idx, int id)
{
	if (idx == 0)
	{
		pthread_mutex_lock(&(*philo)->mutex_start_dining);
		(*philo)->start_dining = (time_get() - (*philo)->input->start_time);
		pthread_mutex_unlock(&(*philo)->mutex_start_dining);
	}
	if (idx == 1)
	{
		pthread_mutex_lock(&(*philo)[id].mutex_start_dining);
		if ((time_get() - (*philo)->input->start_time)
			- (*philo)[id].start_dining >= (*philo)->input->time_life)
		{
			pthread_mutex_unlock(&(*philo)[id].mutex_start_dining);
			return (1);
		}
		pthread_mutex_unlock(&(*philo)[id].mutex_start_dining);
	}
	return (0);
}

int	monitor(t_input *input, t_philo **philo)
{
	int	idx;

	while (!check_died(philo) && \
		!check_dining(philo) && input->meals != 0)
	{
		idx = 0;
		while (idx < input->count_philo && !check_died(philo) && \
			!check_dining(philo))
		{
			if (check_time_dining(philo, 1, idx))
			{
				pthread_mutex_lock(&(*philo)->input->mutex_print);
				printf("%lld %d died\n", time_get()
					- (*philo)->input->start_time, (*philo)[idx].id_philo);
				pthread_mutex_unlock(&(*philo)->input->mutex_print);
				if (pthread_mutex_lock(&input->mutex_died))
					return (-1);
				input->died = 1;
				pthread_mutex_unlock(&input->mutex_died);
			}
			idx++;
		}
		usleep(1000);
	}
	return (0);
}
