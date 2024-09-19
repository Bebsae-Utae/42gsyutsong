/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:36:14 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/19 16:13:30 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_input	input;
	t_philo	*philo;
	int		error_code;

	philo = NULL;
	error_code = 0;
	if (argc != 5 && argc != 6)
		killer(&input, philo, error_code);
	memset(&input, 0, sizeof(t_input));
	error_code = init_argv(&input, argc, argv);
	if (error_code)
		killer(&input, philo, error_code);
	error_code = init_philo(&philo, &input);
	if (error_code)
		killer(&input, philo, error_code);
	error_code = init_mutex(&input);
	if (error_code)
		killer(&input, philo, error_code);
	error_code = philo_start(&input, philo);
	if (error_code)
		killer(&input, philo, error_code);
	killer(&input, philo, 0);
	return (0);
}
