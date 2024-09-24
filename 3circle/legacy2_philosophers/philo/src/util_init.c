/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:33:46 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/24 15:07:04 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void cleanup_mutexed(t_input *input)
{
    int i;
    for (i = 0; i < input->count_philo; i++)
    {
        pthread_mutex_destroy(&input->mutex_fork[i]);
    }
    free(input->mutex_fork);
    pthread_mutex_destroy(&input->mutex_print);
    pthread_mutex_destroy(&input->mutex_dining);
    pthread_mutex_destroy(&input->mutex_who_died);
    pthread_mutex_destroy(&input->mutex_time);
}

static void	cleanup_mutexes(t_input *input, int count)
{
	int	idx;

	idx = 0;
	while (idx < count)
	{
		pthread_mutex_destroy(&(input->mutex_fork[idx]));
		idx ++;
	}
	free(input->mutex_fork);
	if (count > input->count_philo)
	{
		pthread_mutex_destroy(&(input->mutex_print));
		pthread_mutex_destroy(&(input->mutex_dining));
		pthread_mutex_destroy(&(input->mutex_who_died));
		pthread_mutex_destroy(&(input->mutex_time));
	}
}

// static int	is_simul_over(t_input *input)
// {
// 	int	result;

// 	pthread_mutex_lock(&input->mutex_who_died);
// 	result = input->who_died;
// 	pthread_mutex_unlock(&input->mutex_who_died);
// 	return (result);
// }

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
	if (philo->id_philo % 2 == 0)
	{
		pthread_mutex_lock(&philo->input->mutex_fork[philo->right_fork]);
		print_status(philo, "has taken a right fork");
		pthread_mutex_lock(&philo->input->mutex_fork[philo->left_fork]);
		print_status(philo, "has taken a left fork");
	}
	else
	{
		pthread_mutex_lock(&philo->input->mutex_fork[philo->left_fork]);
		print_status(philo, "has taken a left fork");
		pthread_mutex_lock(&philo->input->mutex_fork[philo->right_fork]);
		print_status(philo, "has taken a right fork");
	}
}

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->input->mutex_dining);
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->input->mutex_time);
	philo->time_last_dining = get_time();
	philo->count_dining ++;
	pthread_mutex_unlock(&philo->input->mutex_time);
	usleep(philo->input->time_dining * 1000);
	pthread_mutex_unlock(&philo->input->mutex_dining);
}

static void set_who_died(t_input *input, int value)
{
	pthread_mutex_lock(&input->mutex_who_died);
	input->who_died = value;
	pthread_mutex_unlock(&input->mutex_who_died);
}

static void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->input->mutex_fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->input->mutex_fork[philo->right_fork]);	
}

static void	sleep_and_think(t_philo *philo)
{
	// pthread_mutex_lock(&philo->input->mutex_time);
	print_status(philo, "is sleeping");
	usleep(philo->input->time_sleep * 1000);
	print_status(philo, "is thinking");
	// pthread_mutex_unlock(&philo->input->mutex_time);
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
			// while (--idx >= 0)
            //     pthread_mutex_destroy(&(input->mutex_fork[idx]));
            // free(input->mutex_fork);
			cleanup_mutexes(input, idx);
			return (1);
		}
		idx ++;
	}
	if (pthread_mutex_init(&(input->mutex_print), NULL) || pthread_mutex_init(&(input->mutex_dining), NULL) || pthread_mutex_init(&(input->mutex_who_died), NULL) || pthread_mutex_init(&(input->mutex_time), NULL))
    {
        cleanup_mutexes(input, input->count_philo + 1);
        return (1);
    }
	// if (pthread_mutex_init(&(input->mutex_print), NULL))
	// {
	// 	free(input->mutex_fork);
	// 	return (1);
	// }
	// if (pthread_mutex_init(&(input->mutex_dining), NULL))
	// {
 	// 	pthread_mutex_destroy(&(input->mutex_print));
    //     free(input->mutex_fork);
	// 	return (1);
	// }
	// if (pthread_mutex_init(&(input->mutex_who_died), NULL))
	// {
	// 	pthread_mutex_destroy(&(input->mutex_print));
	// 	pthread_mutex_destroy(&(input->mutex_dining));
	// 	free(input->mutex_fork);
	// 	return (1);
	// }
	return (0);
}

int	init_data(t_input *input, int argc, char **argv)
{
	int	idx;

	if (parse_arguments(input, argc, argv))
		return (1);
	input->who_died = 0;
	input->simulation_end = 0;
	input->time_start = get_time();
	if (init_mutex(input))
		return (1);
	if (pthread_mutex_init(&input->mutex_simulation_end, NULL))
	{
		cleanup_mutexed(input);
		return (1);
	}
	input->philosophers = malloc(sizeof(t_philo) * input->count_philo);
	if (!input->philosophers)
	{
		cleanup_mutexed(input);
		pthread_mutex_destroy(&input->mutex_simulation_end);
		// free(input->mutex_fork); // Free previously allocated memory
        // pthread_mutex_destroy(&(input->mutex_print));
        // pthread_mutex_destroy(&(input->mutex_dining));
		return (1);
	}
	idx = 0;
	while (idx < input->count_philo)
	{
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

	if (!input->philosophers)
	{
		input->philosophers = malloc(sizeof(t_philo) * (input->count_philo));
		if (!input->philosophers)
			return (1);
	}
	idx = 0;
	while (idx < input->count_philo)
	{
		init_single_philo(&input->philosophers[idx], idx, input);
		if (pthread_create(&input->philosophers[idx].id_thread, NULL, philosopher_routine, &input->philosophers[idx]))
		{
			while (--idx >= 0)
				pthread_join(input->philosophers[idx].id_thread, NULL);
			free(input->philosophers);
			input->philosophers = NULL;
			return (1);
		}
		usleep(1000);
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
	while (!is_simulation_end(input))
	{
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		sleep_and_think(philo);
		if (input->count_all_dining != -1 && philo->count_dining >= input->count_all_dining)
		{
			set_simulation_end(input);
			break ;
		}
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

void	cleanup(t_input *input)
{
	int	idx;
	int	join_result;

	if (input->philosophers)
	{
		idx = 0;
		while (idx < input->count_philo)
		{
			if (input->philosophers[idx].id_thread != 0)
			{
				join_result = pthread_join(input->philosophers[idx].id_thread, NULL);
				printf("%d\n", join_result);
				if (join_result != 0)
					printf("Error joining %d %s\n", idx, "wooo");
			}
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
	pthread_mutex_destroy(&input->mutex_simulation_end);
	pthread_mutex_destroy(&input->mutex_print);
	pthread_mutex_destroy(&input->mutex_dining);
	pthread_mutex_destroy(&input->mutex_who_died);
	pthread_mutex_destroy(&input->mutex_time);
}

int	start_simul(t_input *input)
{
	int	idx;
	// int jdx;
	pthread_t monitor;
	int *thread_created;
	int	monitor_created;
	int	join_result;

	monitor_created = 0;
	input->time_start = get_time();
	thread_created = calloc(input->count_philo, sizeof(int));
	if (!thread_created)
	{
		printf("Failed allocate mem for thread");
		return (1);
	}
	if (pthread_create(&monitor, NULL, monitoring_routine, input))
	{
		monitor_created = 1;
	}
	else
	{
		printf("Failed create monitor thread\n");
		// cleanup(input);
		free(thread_created);
		return (1);
	}
	idx = 0;
	while (idx < input->count_philo)
	{
		if (pthread_create(&input->philosophers[idx].id_thread, NULL, philosopher_routine, &input->philosophers[idx]))
		{
			thread_created[idx] = 1;
		}
		else
		{
			printf("Failed to create philo thread\n");
			// cleanup(input);
			// input->who_died = 1;
			set_who_died(input, 1);
			break ;
			// return (1);
		}
		// thread_created[idx] = 1;
		idx ++;
	}
	idx = 0;
	while (idx < input->count_philo)
	{
		if (thread_created[idx])
		{
			join_result = pthread_join(input->philosophers[idx].id_thread, NULL);
			// pthread_join(input->philosophers[idx].id_thread, NULL);
			if (join_result != 0)
			{
				printf("Error join thread %d\n", idx);
			}
		}
		idx ++;
	}
	// jdx = 0;
	// while (jdx < idx)
	// {
	// 	pthread_join(input->philosophers[jdx].id_thread, NULL);
	// 	printf("%d %d\n", jdx, idx);
	// 	jdx ++;
	// }
	if (monitor_created)
	{
		join_result = pthread_join(monitor, NULL);
		if (join_result != 0)
		{
			printf("Error join monitor thread\n");
		}
	}
	free(thread_created);
	return (0);
}

void	*monitoring_routine(void *arg)
{
	t_input	*input;
	int		idx;
	long long	current_time;

	input = (t_input *)arg;
	while (!is_simulation_end(input))
	{
		idx = 0;
		while (idx < input->count_philo)
		{
			current_time = get_time();
			if (current_time - input->philosophers[idx].time_last_dining > input->time_life)
			{
				print_status(&input->philosophers[idx], "died");
				// input->who_died = 1;
				set_who_died(input, 1);
				set_simulation_end(input);
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

void	set_simulation_end(t_input *input)
{
	pthread_mutex_lock(&input->mutex_simulation_end);
	input->simulation_end = 1;
	pthread_mutex_unlock(&input->mutex_simulation_end);
}

int	is_simulation_end(t_input *input)
{
	int	result;

	pthread_mutex_lock(&input->mutex_simulation_end);
	result = input->simulation_end;
	pthread_mutex_unlock(&input->mutex_simulation_end);
	return (result);
}