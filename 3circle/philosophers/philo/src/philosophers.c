/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:36:14 by yutsong           #+#    #+#             */
/*   Updated: 2024/10/14 18:58:08 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_input	input;
	t_philo	*philo;

	if ((argc != 5 && argc != 6) || init_input(&input, argc, argv))
		return (1);
	if (!init_philo(&input, &philo))
		return (kill_and_cleanup(&input, NULL, 1));
	if (philo_create(&philo))
		return (kill_and_cleanup(&input, philo, 1));
	if (monitor(&input, &philo))
	{
		killer_set(&philo, &input);
		return (1);
	}
	killer_set(&philo, &input);
	return (0);
}
