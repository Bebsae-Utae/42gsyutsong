/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:32:13 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/19 19:53:17 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread(void *argv)
{
	t_input	*input;
	t_philo	*philo;

	philo = argv;
	input = philo->input;
	if (philo->id_philo % 2 == 0)
		time_wasted((long long)input->time_sleep, input);
	while (!input->monitor)
	{
		if (input->count_philo - 1 == philo->id_philo
			&& philo->count_dining == 0)
			usleep(1);
		philo_action(input, philo);
		if (input->count_philo == 1)
			time_wasted((long long)input->time_sleep, input);
		if (input->time_dining == philo->count_dining)
		{
			input->monitor ++;
			break ;
		}
		printer(input, philo, philo->id_philo, "is sleeping");
		time_wasted((long long)input->time_sleep, input);
		printer(input, philo, philo->id_philo, "is thinking");
	}
	return (0);
}

int	philo_start(t_input *input, t_philo *philo)
{
	int	idx;

	idx = 0;
	while (idx < input->count_philo)
	{
		philo[idx].time_start_thread = time_get();
		if (pthread_create(&(philo[idx].id_thread),
				NULL, philo_thread, &(philo[idx])))
			return (1);
		idx ++;
	}
	checker(input, philo);
	idx = 0;
	while (idx < input->count_philo)
		pthread_join(philo[idx++].id_thread, NULL);
	return (0);
}

int	philo_action(t_input *input, t_philo *philo)
{
	pthread_mutex_lock(&(input->mutex_fork[philo->left_fork]));
	printer(input, philo, philo->id_philo, "has taken a left fork");
	if (input->count_philo != 1)
	{
		pthread_mutex_lock(&(input->mutex_fork[philo->right_fork]));
		printer(input, philo, philo->id_philo, "has taken a right fork");
		printer(input, philo, philo->id_philo, "is eating");
		philo->time_last_dining = time_get();
		philo->count_dining ++;
		time_wasted((long long)input->time_dining, input);
		pthread_mutex_unlock(&(input->mutex_fork[philo->right_fork]));
	}
	pthread_mutex_unlock(&(input->mutex_fork[philo->left_fork]));
	return (0);
}
