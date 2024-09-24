/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:17:16 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/24 14:42:55 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <memory.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_philo
{
	int				id_philo;
	int				left_fork;
	int				right_fork;
	int				count_dining;
	long long		time_last_dining;
	pthread_t		id_thread;
	struct s_input			*input;
}	t_philo;

typedef struct s_input
{
	int				count_philo;
	int				time_life;
	int				time_dining;
	int				time_sleep;
	int				count_all_dining;
	int				who_died;
	int				simulation_end;
	long long		time_start;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_dining;
	pthread_mutex_t mutex_time;
	pthread_mutex_t mutex_who_died;
	pthread_mutex_t	mutex_simulation_end;
	t_philo			*philosophers;
}	t_input;

int	init_data(t_input *input, int argc, char **argv);
int	init_mutex(t_input *input);
int	parse_arguments(t_input *input, int argc, char **argv);

int	create_philo(t_input *input);
void	*philosopher_routine(void *arg);
void	print_status(t_philo *philo, char *status);

int	start_simul(t_input *input);
void	cleanup(t_input *input);
void	*monitoring_routine(void *arg);

long long	get_time(void);

int	is_simulation_end(t_input *input);
void	set_simulation_end(t_input *input);

int		ft_atoi(const char *str);

#endif