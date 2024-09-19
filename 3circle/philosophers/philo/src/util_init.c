/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:33:46 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/19 17:28:51 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_argv(t_input	*input, int argc, char **argv)
{
	input->count_philo = ft_atoi(argv[1]);
	input->time_life = ft_atoi(argv[2]);
	input->time_dining = ft_atoi(argv[3]);
	input->time_sleep = ft_atoi(argv[4]);
	input->monitor = 0;
	if (input->count_philo <= 0 || input->time_life < 0
		|| input->time_dining < 0 || input->time_sleep < 0)
		return (1);
	if (argc == 6)
	{
		input->count_all_dining = ft_atoi(argv[5]);
		if (input->count_all_dining <= 0)
			return (1);
	}
	return (0);
}

int	init_philo(t_philo **philo, t_input *input)
{
	int	idx;

	idx = 0;
	*philo = malloc(sizeof(t_philo) * input->count_philo);
	if (!philo)
		return (1);
	while (idx < input->count_philo)
	{
		(*philo)[idx].id_philo = idx;
		(*philo)[idx].count_dining = 0;
		(*philo)[idx].left_fork = idx;
		(*philo)[idx].right_fork = (idx + 1) % input->count_philo;
		(*philo)[idx].time_last_dining = 0;
		(*philo)[idx].time_start_thread = 0;
		(*philo)[idx].input = input;
		idx ++;
	}
	return (0);
}

int	init_mutex(t_input *input)
{
	int	idx;

	if (pthread_mutex_init(&(input->mutex_print), NULL))
		return (1);
	input->mutex_fork = malloc(sizeof(pthread_mutex_t) * input->count_philo);
	if (!(input->mutex_fork))
		return (1);
	idx = 0;
	while (idx < input->count_philo)
	{
		if (pthread_mutex_init(&(input->mutex_fork[idx]), NULL))
			return (1);
		idx ++;
	}
	return (0);
}
