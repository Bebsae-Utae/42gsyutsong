/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:36:14 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/30 16:03:11 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_input	input;
	t_philo	*philo;
	int		error_code;

	if (argc != 5 && argc != 6)
		// 에러
	memset(&input, 0, sizeof(t_input));
	
}

void	*philo_thread(void *argv)
{
	t_input	*input;
	t_philo	*philo;

	philo = argv;
	input = philo->input;
	if (philo->id_philo % 2 == 0)
		philo_sleep(input);
	while (!input->monitor)
	{
		if (input->count_philo - 1 == philo->id_philo && philo->count_dining == 0)
			usleep(1);
		philo_action(input, philo);
		if (input->count_philo == 1)
			philo_stay((long long)input->time_sleep, input);
		if (input->time_dining == philo->count_dining)
		{
			input->monitor ++;
			break ;
		}
		print_status(input, philo->id_philo, "is sleeping");
		time_spend((long long)input->time_sleep, input);
		print_status(input, philo->id_philo, "is thinking");
	}
	return (0);
}

int	philo_start(t_input *input, t_philo *philo)
{
	int	idx;

	idx = 0;
	while (idx < input->count_philo)
	{
		philo[idx].time_last_dining = get_time();
		if (pthread_create(&(philo[idx].id_thread), NULL, philo_thread, &(philo[idx])))
			return (1);
		idx ++;
	}
	checker(input, philo);
	idx = 0;
	while (idx < input->count_philo)
		pthread_join(philo[idx++].id_thread, NULL);
	return (0);
}

int	philo_action(t_input *input, t_philo *philo)
{
	pthread_mutex_lock(&(input->mutex_fork[philo->right_fork]));
	// 포크 집어들었다 출력
	if (input->count_philo != 1)
	{
		pthread_mutex_lock(&(input->mutex_fork[philo->right_fork]));
		// 포크 집어들었다 출력
		// 먹고있다 출력
		// tlrks philo->time_last_dining =
		philo->count_dining = philo->count_dining + 1;
		//
		pthread_mutex_unlock(&(input->mutex_fork[philo->right_fork])); 
	}
	pthread_mutex_unlock(&(input->mutex_fork[philo->left_fork]));
	return (0);
}

void	checker(t_input *input, t_philo *philo)
{
	int			idx;
	long long	now;

	while (!input->monitor)
	{
		if ((input->time_dining != 0) && (input->count_philo == input->count_all_dining))
		{
			input->monitor = 1;
			break ;
		}
		idx = 0;
		while (idx < input->count_philo)
		{
			//현재시간 받기 now =
			if ((now - philo[idx].time_last_dining) >= input->time_life)
			{
				// 죽었음 출력
				input->monitor = 1;
				break ;
			}
			idx ++;
		}
	}
}

void	printer()
{
	printf("Start \n");
}