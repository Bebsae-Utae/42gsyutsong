/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_CPK.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:37:19 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/20 14:50:09 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checking(t_input *input)
{
	pthread_mutex_lock(&input->mutex_monitor);
	if (input->monitor == 1)
	{
		pthread_mutex_unlock(&input->mutex_monitor);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&input->mutex_monitor);
		return (0);
	}
}

long last_eat(t_input *input, t_philo *philo)
{
    long	last_eat_time;

    pthread_mutex_lock(&(input->mutex_time_last_dining));
    last_eat_time = philo->time_last_dining;
    pthread_mutex_unlock(&(input->mutex_time_last_dining));

    return last_eat_time;
}

void	change_monitor(t_input *input)
{
	pthread_mutex_lock(&(input->mutex_monitor));
	input->monitor = 1;
	pthread_mutex_unlock(&(input->mutex_monitor));
}

void	checker(t_input *input, t_philo *philo)
{
	int			idx;
	long		now;

	while (!checking(input))
	{
		if ((input->time_dining != 0)
			&& (input->count_philo == input->count_all_dining))
		{
			change_monitor(input);
			// input->monitor = 1;
			break ;
		}
		idx = 0;
		while (idx < input->count_philo)
		{
			now = time_get();
			if ((now - last_eat(input, philo)) >= input->time_life)
			// if (now - philo->time_last_dining >= input->time_life)
			{
				printf("die\n");
				// change_monitor(input);
				// input->monitor = 1;
				break ;
			}
			idx ++;
		}
	}
}

int	printer(t_input *input, t_philo *philo, int id, char *msg)
{
	long	now;

	now = time_get();
	if (now == -1)
		return (-1);
	pthread_mutex_lock(&(input->mutex_print));
	if (!(input->monitor))
	{
		if (((id + 1) % 2) == 0)
			printf("\033[31m%ldsec %dth %s %dtimes\033[0m\n", now - philo->time_start_thread, id + 1, msg, philo->count_dining);
		else
			printf("\033[32m%ldsec %dth %s %dtimes\033[0m\n", now - philo->time_start_thread, id + 1, msg, philo->count_dining);
	}
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
	// pthread_mutex_destroy(&(input->mutex_count_dining));
	pthread_mutex_destroy(&(input->mutex_time_last_dining));
	if (error_code)
		printf("errors");
}
