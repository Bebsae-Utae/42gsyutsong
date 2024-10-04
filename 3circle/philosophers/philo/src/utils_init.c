/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:48:34 by yutsong           #+#    #+#             */
/*   Updated: 2024/10/02 13:47:28 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*init_philo(t_input *input)
{
	int		idx;
	t_philo	*philo;

	philo = malloc(input->count_philo * sizeof (*philo));
	if (!philo)
		return (NULL);
	idx = 0;
	while (idx < input->count_philo && philo)
	{
		philo[idx].id_philo = idx + 1;
		philo[idx].start_dining = 0;
		if (pthread_mutex_init(&philo[idx].mutex_left_fork, NULL))
		{
			killer_philo(&philo, idx, 0, 0);
			return (NULL);
		}
		if (idx != input->count_philo - 1)
			philo[idx].mutex_right_fork = &philo[idx + 1].mutex_left_fork;
		else
			philo[idx].mutex_right_fork = &philo[0].mutex_left_fork;
		philo[idx].input = input;
		idx++;
	}
	return (philo);
}

int	init_mutexes(t_input *input)
{
	pthread_mutex_init(&input->mutex_data, NULL);
	if (pthread_mutex_init(&input->mutex_died, NULL))
	{
		pthread_mutex_destroy(&input->mutex_data);
		return (1);
	}
	else if (pthread_mutex_init(&input->mutex_dining, NULL))
	{
		pthread_mutex_destroy(&input->mutex_data);
		pthread_mutex_destroy(&input->mutex_died);
		return (1);
	}
	else if (pthread_mutex_init(&input->mutex_print, NULL))
	{
		pthread_mutex_destroy(&input->mutex_data);
		pthread_mutex_destroy(&input->mutex_died);
		pthread_mutex_destroy(&input->mutex_dining);
		return (1);
	}
	return (0);
}

int	init_input(t_input *input, int argc, char **argv)
{
	input->count_philo = ft_atoi(argv[1]);
	input->time_life = ft_atoi(argv[2]);
	input->time_dining = ft_atoi(argv[3]);
	input->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input->meals = ft_atoi(argv[5]);
	else
		input->meals = -1;
	if (!check_parse(input, argc))
		return (1);
	if (init_mutexes(input) || !input->count_philo)
		return (1);
	return (0);
}

int	check_parse(t_input *input, int argc)
{
	if (input->count_philo <= 0)
		return (0);
	if (input->time_life <= 0)
		return (0);
	if (input->time_dining <= 0)
		return (0);
	if (input->time_sleep <= 0)
		return (0);
	if (argc == 6 && input->meals <= 0)
		return (0);
	return (1);
}
