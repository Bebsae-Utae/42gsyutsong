/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:33:46 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/23 15:57:42 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_arguments(t_input *input, int argc, char **argv)
{
	input->count_philo = ft_atoi(argv[1]);
	input->time_life = ft_atoi(argv[2]);
	input->time_dining = ft_atoi(argv[3]);
	input->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input->count_all_dining = ft_atoi(argv[5]);
	else
		input->count_all_dining = -1;
	if (input->count_philo <= 0 || input->time_life <= 0 || input->time_dining <= 0 || input->time_sleep <= 0 || (argc == 6 && input->count_all_dining <= 0))
		return (1);
	return (0);
}

int	init_mutex(t_input *input)
{
	int	idx;

	input->mutex_fork = malloc(sizeof(pthread_mutex_t) * input->count_philo);
	if (!input->mutex_fork)
		return (1);
	idx = 0;
	while (idx < input->count_philo)
	{
		if (pthread_mutex_init(&(input->mutex_fork[idx]), NULL))
			return (1);
		idx ++;
	}
	if (pthread_mutex_init(&(input->mutex_print), NULL))
		return (1);
	return (0);
}

int	init_data(t_input *input, int argc, char **argv)
{
	int	idx;

	if (parse_arguments(input, argc, argv))
		return (1);
	input->who_died = 0;
	input->time_start = get_time();
	if (init_mutex(input))
		return (1);
	input->philosophers = malloc(sizeof(t_philo) * input->count_philo);
	if (!input->philosophers)
		return (1);
	idx = 0;
	while (idx < input->count_philo)
	{
		input->philosophers[idx].id_philo = idx + 1;
		input->philosophers[idx].left_fork = idx;
		input->philosophers[idx].right_fork = (idx + 1) % input->count_philo;
		input->philosophers[idx].count_dining = 0;
		input->philosophers[idx].time_last_dining = input->time_start;
		input->philosophers[idx].input = (struct s_input *)input;
		idx ++;
	}
	return (0);
}

// int	init_argv(t_input	*input, int argc, char **argv)
// {
// 	input->count_philo = ft_atoi(argv[1]);
// 	input->time_life = ft_atoi(argv[2]);
// 	input->time_dining = ft_atoi(argv[3]);
// 	input->time_sleep = ft_atoi(argv[4]);
// 	input->monitor = 0;
// 	if (input->count_philo <= 0 || input->time_life < 0
// 		|| input->time_dining < 0 || input->time_sleep < 0)
// 		return (1);
// 	if (argc == 6)
// 	{
// 		input->count_all_dining = ft_atoi(argv[5]);
// 		if (input->count_all_dining <= 0)
// 			return (1);
// 	}
// 	return (0);
// }

// // 철학자와 philo 구조체가 1:1로 대응
// int	init_philo(t_philo **philo, t_input *input)
// {
// 	int	idx;

// 	idx = 0;
// 	*philo = malloc(sizeof(t_philo) * input->count_philo);
// 	if (!philo)
// 		return (1);
// 	while (idx < input->count_philo)
// 	{
// 		(*philo)[idx].count_dining = 0;
// 		(*philo)[idx].id_philo = idx;
// 		(*philo)[idx].left_fork = idx;
// 		(*philo)[idx].right_fork = (idx + 1) % input->count_philo;
// 		(*philo)[idx].time_last_dining = 0;
// 		(*philo)[idx].time_start_thread = 0;
// 		(*philo)[idx].input = input;
// 		(*philo)[idx].died = 0;
// 		idx ++;
// 	}
// 	return (0);
// }

// int	init_mutex(t_input *input)
// {
// 	int	idx;

// 	if (pthread_mutex_init(&(input->mutex_print), NULL))
// 		return (1);
// 	input->mutex_fork = malloc(sizeof(pthread_mutex_t) * input->count_philo);
// 	if (!(input->mutex_fork))
// 		return (1);
// 	idx = 0;
// 	while (idx < input->count_philo)
// 	{
// 		if (pthread_mutex_init(&(input->mutex_fork[idx]), NULL))
// 			return (1);
// 		idx ++;
// 	}
// 	return (0);
// }
