/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:17:15 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/23 20:37:58 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_input *input)
{
	int	idx;

	if (input->philosophers)
	{
		idx = 0;
		while (idx < input->count_philo)
		{
			pthread_join(input->philosophers[idx].id_thread, NULL);
			idx ++;
		}
		free(input->philosophers);
	}
	if (input->mutex_fork)
	{
		idx = 0;
		while (idx < input->count_philo)
		{
			pthread_mutex_destroy(&input->mutex_fork[idx]);
			idx ++;
		}
		free(input->mutex_fork);
	}
	pthread_mutex_destroy(&input->mutex_print);
	pthread_mutex_destroy(&input->mutex_dining);
	pthread_mutex_destroy(&input->mutex_time);
}

int	start_simul(t_input *input)
{
	int	idx;
	int jdx;
	pthread_t monitor;

	input->time_start = get_time();
	if (pthread_create(&monitor, NULL, monitoring_routine, input))
	{
		printf("Failed create monitor thread\n");
		cleanup(input);
		return (1);
	}
	idx = 0;
	while (idx < input->count_philo)
	{
		if (pthread_create(&input->philosophers[idx].id_thread, NULL, philosopher_routine, &input->philosophers[idx]))
		{
			printf("Failed to create philo thread\n");
			cleanup(input);
			// input->who_died = 1;
			// break ;
			return (1);
		}
		idx ++;
	}
	jdx = 0;
	while (jdx < idx)
	{
		pthread_join(input->philosophers[jdx].id_thread, NULL);
		printf("%d %d\n", jdx, idx);
		jdx ++;
	}
	pthread_join(monitor, NULL);
	return (0);
}

void	*monitoring_routine(void *arg)
{
	t_input	*input;
	int		idx;
	long long	current_time;

	input = (t_input *)arg;
	while (!input->who_died)
	{
		idx = 0;
		while (idx < input->count_philo)
		{
			current_time = get_time();
			if (current_time - input->philosophers[idx].time_last_dining > input->time_life)
			{
				print_status(&input->philosophers[idx], "died");
				input->who_died = 1;
				printf("Philosopher %d died, setting who_died flag.\n", idx);
				// break ;
				return (NULL);
			}
			idx ++;
		}
		// if (input->who_died)
		// 	break ;
		usleep(1000);

	}
	return (NULL);
}

// void    monitoring(t_philo *philo, t_input *input)
// {
// 	int		idx;
// 	long	now_time;

// 	while (!checking(input))
// 	{
// 		// 모든 철학자의 식사가 끝나면 종료
// 		printf("%d %d\n", philo->count_dining, input->count_all_dining);
// 		// if (input->count_all_dining != 0 && last_eat(input, philo) == input->count_all_dining)
// 		if (input->count_all_dining != 0 && (philo->count_dining == input->count_all_dining))
// 		{
// 			change_monitor(input);
// 			break ;
// 		}
// 		idx = 0;
// 		while (idx < input->count_philo)
// 		{
// 			now_time = time_get();
// 			printf("now            :%ld\n", now_time);
// 			printf("last_eat       :%ld\n", eat_last_time(&philo[idx]));
// 			printf("life           :%d\n", input->time_life);
// 			printf("last_eat_origin:%ld\n", philo->time_last_dining);
// 			if ((int)(now_time - eat_last_time(&philo[idx])) > input->time_life)
// 			{
// 				printf("ff\n");
// 				change_monitor(input);
// 				break ;
// 			}
// 			idx ++;
// 		}
// 		usleep(10);
// 	}
// }

// long	eat_last_time(t_philo *philo)
// {
// 	long	last_eat_time;

//     pthread_mutex_lock(&(philo->input->mutex_time_last_dining));
//     last_eat_time = philo->time_last_dining;
// 	printf("in_eat_last_time:%ld\n", last_eat_time);
//     pthread_mutex_unlock(&(philo->input->mutex_time_last_dining));

//     return last_eat_time;
// }