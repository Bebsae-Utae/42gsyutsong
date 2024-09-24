/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:36:14 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/23 20:33:47 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_input	input;
	// t_philo	*philo;
	int		error_code;

	// philo = NULL;
	// error_code = 0;
	if (argc != 5 && argc != 6)
	{
		printf("Invalid arguments\n");
		return (1);
		// killer(&input, philo, error_code);
	}
	memset(&input, 0, sizeof(t_input));
	// error_code = init_argv(&input, argc, argv);
	error_code = init_data(&input, argc, argv);
	if (error_code)
	{
		printf("Init failed\n");
		return (error_code);
	}
	error_code = create_philo(&input);
	if (error_code)
	{
		printf("Failed to create philo\n");
		cleanup(&input);
		return (error_code);
	}

	error_code = start_simul(&input);
	if (error_code)
	{
		printf("Simul failed\n");
		cleanup(&input);
		return (error_code);
	}
	cleanup(&input);
	return (0);
	// 	killer(&input, philo, error_code);
	// error_code = init_philo(&philo, &input);
	// if (error_code)
	// 	killer(&input, philo, error_code);
	// error_code = init_mutex(&input);
	// if (error_code)
	// 	killer(&input, philo, error_code);
	// error_code = philo_start(&input, philo);
	// if (error_code)
	// 	killer(&input, philo, error_code);
	// killer(&input, philo, 0);
	// return (0);
}
