/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:36:14 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/24 14:18:31 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_input	input;
	int		error_code;

	if (argc != 5 && argc != 6)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	memset(&input, 0, sizeof(t_input));
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
}
