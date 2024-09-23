/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:33:46 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/23 20:39:39 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_single_philo(t_philo *philo, int id, t_input *input)
{
	philo->id_philo = id + 1;
	philo->left_fork = id;
	philo->right_fork = (id + 1) % (input->count_philo);
	philo->count_dining = 0;
	philo->time_last_dining = input->time_start;
	philo->input = input;
}

static void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->input->mutex_fork[philo->left_fork]);
	print_status(philo, "has taken a left fork");
	pthread_mutex_lock(&philo->input->mutex_fork[philo->right_fork]);
	print_status(philo, "has taken a right fork");
}

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->input->mutex_dining);
	print_status(philo, "is eating");
	philo->time_last_dining = get_time();
	philo->count_dining ++;
	usleep(philo->input->time_dining * 1000);
	pthread_mutex_unlock(&philo->input->mutex_dining);
}

static void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->input->mutex_fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->input->mutex_fork[philo->right_fork]);	
}

static void	sleep_and_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->input->mutex_time);
	print_status(philo, "is sleeping");
	usleep(philo->input->time_sleep * 1000);
	print_status(philo, "is thinking");
	pthread_mutex_unlock(&philo->input->mutex_time);
}

int	parse_arguments(t_input *input, int argc, char **argv)
{
	input->count_philo = ft_atoi(argv[1]);
	input->time_life = ft_atoi(argv[2]);
	input->time_dining = ft_atoi(argv[3]);
	input->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input->count_all_dining = ft_atoi(argv[5]);
	else
		input->count_all_dining = -1;
	if (input->count_philo <= 0 || input->time_life <= 0 || input->time_dining <= 0 || input->time_sleep <= 0 || (argc == 6 && input->count_all_dining <= 0))
		return (1);
	return (0);
}

int	init_mutex(t_input *input)
{
	int	idx;

	input->mutex_fork = malloc(sizeof(pthread_mutex_t) * input->count_philo);
	if (!input->mutex_fork)
		return (1);
	idx = 0;
	while (idx < input->count_philo)
	{
		if (pthread_mutex_init(&(input->mutex_fork[idx]), NULL))
		{
			while (--idx >= 0)
                pthread_mutex_destroy(&(input->mutex_fork[idx]));
            free(input->mutex_fork);
			return (1);
		}
		idx ++;
	}
	if (pthread_mutex_init(&(input->mutex_print), NULL))
	{
		free(input->mutex_fork);
		return (1);
	}
	if (pthread_mutex_init(&(input->mutex_dining), NULL))
	{
 		pthread_mutex_destroy(&(input->mutex_print));
        free(input->mutex_fork);
		return (1);
	}
	return (0);
}

int	init_data(t_input *input, int argc, char **argv)
{
	int	idx;

	if (parse_arguments(input, argc, argv))
		return (1);
	input->who_died = 0;
	input->time_start = get_time();
	if (init_mutex(input))
		return (1);
	input->philosophers = malloc(sizeof(t_philo) * input->count_philo);
	if (!input->philosophers)
	{
		free(input->mutex_fork); // Free previously allocated memory
        pthread_mutex_destroy(&(input->mutex_print));
        pthread_mutex_destroy(&(input->mutex_dining));
		return (1);
	}
	idx = 0;
	while (idx < input->count_philo)
	{
		// input->philosophers[idx].id_philo = idx + 1;
		// input->philosophers[idx].left_fork = idx;
		// input->philosophers[idx].right_fork = (idx + 1) % input->count_philo;
		// input->philosophers[idx].count_dining = 0;
		// input->philosophers[idx].time_last_dining = input->time_start;
		// input->philosophers[idx].input = (struct s_input *)input;
		init_single_philo(&input->philosophers[idx], idx, input);
		idx ++;
	}
	return (0);
}

long long	get_time(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	create_philo(t_input *input)
{
	int	idx;

	input->philosophers = malloc(sizeof(t_philo) * (input->count_philo));
	if (!input->philosophers)
		return (1);
	idx = 0;
	while (idx < input->count_philo)
	{
		init_single_philo(&input->philosophers[idx], idx, input);
		if (pthread_create(&input->philosophers[idx].id_thread, NULL, philosopher_routine, &input->philosophers[idx]))
		{
			while (--idx >= 0)
				pthread_join(input->philosophers[idx].id_thread, NULL);
			free(input->philosophers);
			return (1);
		}
		idx ++;
	}
	return (0);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;
	t_input	*input;

	philo = (t_philo *)arg;
	input = philo->input;
	if (philo->id_philo % 2 == 0)
		usleep(1000);
	while (!input->who_died)
	{
		printf("222222222222222222\n");
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		sleep_and_think(philo);
		if (input->count_all_dining != -1 && philo->count_dining >= input->count_all_dining)
			break ;
	}
    printf("Philosopher %d exiting loop.\n", philo->id_philo);
	return (NULL);
}

void	print_status(t_philo *philo, char *status)
{
	long long	current_time;

	pthread_mutex_lock(&philo->input->mutex_print);
	if (!philo->input->who_died)
	{
		current_time = get_time() - philo->input->time_start;
		printf("%lld %d %s\n", current_time, philo->id_philo, status);
	}
	pthread_mutex_unlock(&philo->input->mutex_print);
}

// int	init_argv(t_input	*input, int argc, char **argv)
// {
// 	input->count_philo = ft_atoi(argv[1]);
// 	input->time_life = ft_atoi(argv[2]);
// 	input->time_dining = ft_atoi(argv[3]);
// 	input->time_sleep = ft_atoi(argv[4]);
// 	input->monitor = 0;
// 	if (input->count_philo <= 0 || input->time_life < 0
// 		|| input->time_dining < 0 || input->time_sleep < 0)
// 		return (1);
// 	if (argc == 6)
// 	{
// 		input->count_all_dining = ft_atoi(argv[5]);
// 		if (input->count_all_dining <= 0)
// 			return (1);
// 	}
// 	return (0);
// }

// // 철학자와 philo 구조체가 1:1로 대응
// int	init_philo(t_philo **philo, t_input *input)
// {
// 	int	idx;

// 	idx = 0;
// 	*philo = malloc(sizeof(t_philo) * input->count_philo);
// 	if (!philo)
// 		return (1);
// 	while (idx < input->count_philo)
// 	{
// 		(*philo)[idx].count_dining = 0;
// 		(*philo)[idx].id_philo = idx;
// 		(*philo)[idx].left_fork = idx;
// 		(*philo)[idx].right_fork = (idx + 1) % input->count_philo;
// 		(*philo)[idx].time_last_dining = 0;
// 		(*philo)[idx].time_start_thread = 0;
// 		(*philo)[idx].input = input;
// 		(*philo)[idx].died = 0;
// 		idx ++;
// 	}
// 	return (0);
// }

// int	init_mutex(t_input *input)
// {
// 	int	idx;

// 	if (pthread_mutex_init(&(input->mutex_print), NULL))
// 		return (1);
// 	input->mutex_fork = malloc(sizeof(pthread_mutex_t) * input->count_philo);
// 	if (!(input->mutex_fork))
// 		return (1);
// 	idx = 0;
// 	while (idx < input->count_philo)
// 	{
// 		if (pthread_mutex_init(&(input->mutex_fork[idx]), NULL))
// 			return (1);
// 		idx ++;
// 	}
// 	return (0);
// }
