/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:17:15 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/20 15:05:38 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    monitoring(t_philo *philo, t_input *input)
{
	int		idx;
	long	now_time;

	while (!checking(input))
	{
		// if (input->count_all_dining != 0 && last_eat(philo, input) == input->count_all_dining)
		// if (input->count_all_dining != 0 && philo->count_dining == input->count_all_dining)
		// {
		// 	change_monitor(input);
		// 	break ;
		// }
		idx = 0;
		while (idx < input->count_philo)
		{
			now_time = time_get();
			printf("now            :%ld\n", now_time);
			printf("last_eat       :%ld\n", eat_last_time(&philo[idx]));
			printf("life           :%d\n", input->time_life);
			printf("last_eat_origin:%ld\n", philo->time_last_dining);
			if ((int)(now_time - eat_last_time(&philo[idx])) > input->time_life)
			{
				printf("ff\n");
				change_monitor(input);
				break ;
			}
			idx ++;
		}
		usleep(10);
	}
}

long	eat_last_time(t_philo *philo)
{
	long	last_eat_time;

    pthread_mutex_lock(&(philo->input->mutex_time_last_dining));
    last_eat_time = philo->time_last_dining;
	printf("in_eat_last_time:%ld\n", last_eat_time);
    pthread_mutex_unlock(&(philo->input->mutex_time_last_dining));

    return last_eat_time;
}