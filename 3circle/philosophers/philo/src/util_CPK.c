/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_CPK.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:37:19 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/19 16:38:13 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	checker(t_input *input, t_philo *philo)
{
	int			idx;
	long long	now;

	while (!input->monitor)
	{
		if ((input->time_dining != 0)
			&& (input->count_philo == input->count_all_dining))
		{
			input->monitor = 1;
			break ;
		}
		idx = 0;
		while (idx < input->count_philo)
		{
			now = time_get();
			if ((now - philo[idx].time_last_dining) >= input->time_life)
			{
				// printf("%lld\n", now - philo[idx].time_start_thread);
				input->monitor = 1;
				break ;
			}
			idx ++;
		}
	}
}

int	printer(t_input *input, t_philo *philo, int id, char *msg)
{
	long long	now;

	now = time_get();
	if (now == -1)
		return (-1);
	pthread_mutex_lock(&(input->mutex_print));
	if (!(input->monitor))
		printf("%lld %d %s\n", now - philo->time_start_thread, id + 1, msg);
	pthread_mutex_unlock(&(input->mutex_print));
	return (0);
}

void	killer(t_input *input, t_philo *philo, int error_code)
{
	int	idx;

	if (philo)
		free(philo);
	if (input->mutex_fork)
	{
		idx = 0;
		while (idx < input->count_philo)
		{
			pthread_mutex_destroy(&(input->mutex_fork[idx]));
			idx ++;
		}
		free(input->mutex_fork);
	}
	pthread_mutex_destroy(&(input->mutex_print));
	pthread_mutex_destroy(&(input->mutex_monitor));
	pthread_mutex_destroy(&(input->mutex_count_dining));
	pthread_mutex_destroy(&(input->mutex_time_last_dining));
	if (error_code)
		printf("errors");
}
