/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:48:34 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/24 19:51:30 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// ft_atol은 없어도 되지 않나 ?
int	*parser(char **argv, int *args)
{
	int	idx;

	idx = 0;
	while (argv[idx + 1])
	{
		args[idx] = ft_atoi(argv[idx + 1]);
		// if (args[idx] == -1 || args[idx] != ft_atol(argv[idx + 1]))
		if (args[idx] == -1)
			return (NULL);
		idx++;
	}
	if (args[0] == 0)
		return (NULL);
	if (argv[5] == NULL)
		args[4] = -1;
	return (args);
}

t_philo	*init_philo(t_input *input)
{
	int		idx;
	t_philo	*philo;

	idx = 0;
	input->done_dining = 0;
	philo = malloc(input->count_philo * sizeof (*philo));
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

t_input	init_input(char **argv)
{
	t_input input;
	
	if (parser(argv, (int *)&input) == NULL)
	{
		printf("Invalid arguments.\n");
		printf("Put 4 or 5 arguments(positive ints).\n");
		input.meals = 0;
	}
	return (input);
}