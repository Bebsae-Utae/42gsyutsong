/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:01:38 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/24 20:07:54 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	mutex_done_dining(t_philo **philo)
{
	pthread_mutex_lock(&(*philo)->input->mutex_dining);
	(*philo)->input->done_dining ++;
	pthread_mutex_unlock(&(*philo)->input->mutex_dining);
}

int	mutex_take_fork(t_philo **philo)
{
	int	f2;

	f2 = 0;
	if (!check_died(philo) && !check_dining(philo))
	{
		pthread_mutex_lock(&(*philo)->mutex_left_fork);
		f2 += 1;
		if ((*philo)->input->count_philo != 1)
		{
			pthread_mutex_lock((*philo)->mutex_right_fork);
			f2 += 1;
		}
		mutex_printer(philo, "%lld %d has taken a fork\n");
	}
	return (f2);
}

void	mutex_count_philo(t_philo **philo)
{
	pthread_mutex_lock(&(*philo)->input->mutex_dining);
	(*philo)->input->done_dining = (*philo)->input->count_philo;
	pthread_mutex_unlock(&(*philo)->input->mutex_dining);
	pthread_mutex_unlock(&(*philo)->input->mutex_data);
}

void	mutex_printer(t_philo **philo, char *str)
{
	pthread_mutex_lock(&(*philo)->input->mutex_print);
	if (!check_dining(philo) && !check_died(philo))
	{
		printf(str, time_get() - (*philo)->input->start_time, (*philo)->id_philo);
	}
	pthread_mutex_unlock(&(*philo)->input->mutex_print);
}
