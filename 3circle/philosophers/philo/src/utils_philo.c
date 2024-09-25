/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:54:07 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/25 15:49:44 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(t_philo *philo)
{
	int	cnt_dining;
	int	cnt_fork;

	cnt_dining = 0;
	if (philo->id_philo % 2 == 0)
		time_sleep(&philo, 1);
	while (!check_dining(&philo) && philo->input->meals != 0
		&& !check_died(&philo))
	{
		if (philo->input->count_philo != 1)
			mutex_printer(&philo, "%lld %d is thinking\n");
		cnt_fork = mutex_take_fork(&philo);
		philo_eat(&philo, cnt_fork);
		if (cnt_fork > 1)
			pthread_mutex_unlock((philo)->mutex_right_fork);
		if (philo->input->meals > 0
			&& (cnt_dining + 1) == philo->input->meals && cnt_fork == 2)
			mutex_done_dining(&philo);
		philo_sleep(&philo, cnt_fork);
		cnt_dining++;
		while (!check_died(&philo)
			&& (philo->input->count_philo == 1 && cnt_dining))
			usleep(100);
	}
	return (philo);
}

int	philo_create(t_philo **philo)
{
	int	idx;

	idx = 0;
	(*philo)->input->start_time = time_get();
	(*philo)->input->died = 0;
	while (idx < (*philo)->input->count_philo)
	{
		if (pthread_create(&(*philo)[idx].philo_thread, NULL, \
			(void *(*)(void *))philo_routine, &(*philo)[idx]))
		{
			mutex_count_philo(philo);
			killer_philo(philo, -1, idx, idx);
			return (1);
		}
		if (pthread_mutex_init(&(*philo)[idx].mutex_start_dining, NULL))
		{
			mutex_count_philo(philo);
			killer_philo(philo, -1, idx, idx + 1);
			return (1);
		}
		idx++;
	}
	return (0);
}

int	philo_join(t_philo **philo, int philonb)
{
	int	idx;
	int	error;

	idx = 0;
	error = 0;
	while (idx < philonb)
	{
		if (pthread_join((*philo)[idx].philo_thread, NULL) != 0)
			error++;
		idx++;
	}
	if (idx == philonb)
		return (0);
	return (error);
}

void	philo_eat(t_philo **philo, int fork)
{
	if (fork == 2)
	{
		check_time_dining(philo, 0, 0);
		mutex_printer(philo, "%lld %d has taken a fork\n");
		mutex_printer(philo, "%lld %d is eating\n");
		time_sleep(philo, (*philo)->input->time_dining);
		pthread_mutex_unlock(&(*philo)->mutex_left_fork);
	}
}

void	philo_sleep(t_philo **philo, int nb)
{
	if (nb == 2)
	{
		mutex_printer(philo, "%lld %d is sleeping\n");
		time_sleep(philo, (*philo)->input->time_sleep);
	}
}
