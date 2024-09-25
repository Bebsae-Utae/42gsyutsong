/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:17:16 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/25 13:59:33 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_input
{
	int				count_philo;
	int				time_life;
	int				time_dining;
	int				time_sleep;
	int				meals;
	int				done_dining;
	int				died;
	long long		start_time;
	pthread_mutex_t	mutex_data;
	pthread_mutex_t	mutex_dining;
	pthread_mutex_t	mutex_died;
	pthread_mutex_t	mutex_print;
}	t_input;

typedef struct s_philo
{
	int				id_philo;
	long long int	start_dining;
	pthread_t		philo_thread;
	pthread_mutex_t	mutex_start_dining;
	pthread_mutex_t	mutex_left_fork;
	pthread_mutex_t	*mutex_right_fork;
	t_input			*input;
}	t_philo;

t_input		init_input(char **argv);
int			init_mutexes(t_input *input);
t_philo		*init_philo(t_input *input);
int			*parser(char **argv, int *args);

void		killer_mutexes(t_input *input);
void		killer_set(t_philo **philo, t_input *input);
void		killer_philo(t_philo **philo, int forknb, int eatnb, int philonb);

int			monitor(t_input *input, t_philo **philo);
int			check_died(t_philo **philo);
int			check_time_dining(t_philo **philo, int idx, int id);
int			check_dining(t_philo **philo);

void		mutex_done_dining(t_philo **philo);
void		mutex_count_philo(t_philo **philo);
int			mutex_take_fork(t_philo **philo);
void		mutex_printer(t_philo **philo, char *str);

void		time_sleep(t_philo **philo, long long msec);
long long	time_get(void);

int			philo_create(t_philo **philo);
int			philo_join(t_philo **philo, int philonb);
void		philo_eat(t_philo **philo, int fork);
void		philo_sleep(t_philo **philo, int nb);
void		*philo_routine(t_philo *philo);

int			ft_atoi(const char *str);

#endif