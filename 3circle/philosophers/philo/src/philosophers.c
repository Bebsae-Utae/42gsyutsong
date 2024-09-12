/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:36:14 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/12 15:46:07 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_input	input;
	t_philo	*philo;
	int		error_code;

	if (argc != 5 && argc != 6)
		killer(0, &input);
	memset(&input, 0, sizeof(t_input));
	error_code = init_argv(&input, argc, argv);
	if (error_code)
		killer(1, &input);
	error_code = init_mutex(&input);
	if (error_code)
		killer(1, &input);
	error_code = init_philo(&philo, &input);
	if (error_code)
		killer(2, &input);
	// 아래 함수에서 코어 덤프
	error_code = philo_start(&input, philo);
	if (error_code)
		killer(3, &input);
	return(0);
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
			time_wasted((long long)input->time_sleep, input);
		if (input->time_dining == philo->count_dining)
		{
			input->monitor ++;
			break ;
		}
		printer(input, philo, philo->id_philo, "is sleeping");
		time_wasted((long long)input->time_sleep, input);
		printer(input, philo, philo->id_philo, "is thinking");
	}
	return (0);
}

void	philo_sleep(t_input *input)
{
	time_wasted((long long)input->time_sleep, input);
}

int	philo_start(t_input *input, t_philo *philo)
{
	int	idx;

	idx = 0;
	while (idx < input->count_philo)
	{
		philo[idx].time_start_thread = time_get();
		if (pthread_create(&(philo[idx].id_thread), NULL, philo_thread, &(philo[idx])))
		{
			return (1);
		}
		idx ++;
	}
	// 아래 함수에서 코어 덤프
	checker(input, philo);
	idx = 0;
	while (idx < input->count_philo)
		pthread_join(philo[idx++].id_thread, NULL);
	return (0);
}

int	philo_action(t_input *input, t_philo *philo)
{
	pthread_mutex_lock(&(input->mutex_fork[philo->left_fork]));
	// 포크 집어들었다 출력
	printer(input, philo, philo->id_philo, "has taken a fork");
	if (input->count_philo != 1)
	{
		pthread_mutex_lock(&(input->mutex_fork[philo->right_fork]));
		// 포크 집어들었다 출력
		printer(input, philo, philo->id_philo, "has taken a fork");
		// 먹고있다 출력
		printer(input, philo, philo->id_philo, "is eating");
		philo->time_last_dining = time_get();
		philo->count_dining = philo->count_dining + 1;
		//
		time_wasted((long long)input->time_dining, input);
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
			now = time_get();
			if ((now - philo[idx].time_start_thread) >= input->time_life)
			{
				printf("%lld\n", now - philo[idx].time_start_thread);
				// 죽었음 출력
				input->monitor = 1;
				break ;
			}
			idx ++;
		}
	}
}

int	printer(t_input *input, t_philo *philo, int id, char *msg)
{
	long long	now;

	now = time_get();
	if (now == -1)
		return (-1);
	pthread_mutex_lock(&(input->mutex_print));
	if (!(input->monitor))
	{
		printf("%lld %d %s \n", now - philo->time_start_thread, id + 1, msg);
	}
	pthread_mutex_unlock(&(input->mutex_print));
	return (0);
}

void	killer(int code, t_input *input)
{
	if (code == 0)
		exit(0);
	else if (code == 1)
	{
		// 메모리 free
		free(input);
		exit(0);
	}
	else if (code == 2)
	{
		// 메모리 free1
		free(input);
		// 메모리 free2
		exit(0);
	}
}

void	time_wasted(long long wait_time, t_input *input)
{
	long long	start;
	long long	now;

	start = time_get();
	while (!(input->monitor))
	{
		now = time_get();
		if ((now - start) >= wait_time)
			break ;
		usleep(10);
	}
}

long	time_get(void)
{
	struct timeval	time;
	long			result;

	gettimeofday(&time, NULL);
	result = ((size_t)time.tv_sec * 1000) + ((size_t)time.tv_usec / 1000);
	return (result);
}