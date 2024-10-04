/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:36:14 by yutsong           #+#    #+#             */
/*   Updated: 2024/10/02 13:34:28 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_input	input;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (1);
	if (init_input(&input, argc, argv))
		return (1);
	philo = init_philo(&input);
	if (!philo)
	{
		killer_mutexes(&input); // 체크 필요
		return (1);
	}
	pthread_mutex_lock(&input.mutex_data);
	if (philo_create(&philo))
	{
		free(philo);
		killer_mutexes(&input);
		return (1);
	}
	pthread_mutex_unlock(&input.mutex_data);
	if (monitor(&input, &philo))
	{
		killer_set(&philo, &input);
		return (1);
	}
	killer_set(&philo, &input);
	return (0);
}
