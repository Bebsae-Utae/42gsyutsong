/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_killer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:50:18 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/25 16:13:26 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	killer_mutexes(t_input *input)
{
	pthread_mutex_destroy(&input->mutex_data);
	pthread_mutex_destroy(&input->mutex_died);
	pthread_mutex_destroy(&input->mutex_print);
	pthread_mutex_destroy(&input->mutex_dining);
}

void	killer_philo(t_philo **philo, int forknb, int eatnb, int philonb)
{
	int	idx;

	if (forknb == -1)
		forknb = (*philo)->input->count_philo;
	philo_join(philo, philonb);
	idx = 0;
	while (idx < eatnb)
	{
		pthread_mutex_destroy(&(*philo)[idx].mutex_start_dining);
		idx++;
	}
	idx = 0;
	while (idx < forknb)
	{
		pthread_mutex_destroy(&(*philo)[idx].mutex_left_fork);
		idx++;
	}
	free(*philo);
}

void	killer_set(t_philo **philo, t_input *input)
{
	killer_philo(philo, -1, input->count_philo, input->count_philo);
	killer_mutexes(input);
}
