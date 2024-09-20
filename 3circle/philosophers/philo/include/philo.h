/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:17:16 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/20 15:59:30 by yutsong          ###   ########.fr       */
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

typedef struct s_input
{
	// 철학자 수
	int				count_philo;
	// 총 식사 수
	int				count_all_dining;
	// 생명 주기
	int				time_life;
	// 식사 시간
	int				time_dining;
	// 수면 시간
	int				time_sleep;
	// 상태 체크
	int				monitor;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_monitor;
	pthread_mutex_t	mutex_count_dining;
	pthread_mutex_t	mutex_time_last_dining;
}	t_input;

typedef struct s_philo
{
	int			id_philo;
	int			count_dining;
	int			left_fork;
	int			right_fork;
	long		time_last_dining;
	long		time_start_thread;
	pthread_t	id_thread;
	t_input		*input;
}	t_philo;

int		init_argv(t_input	*input, int argc, char **argv);
int		init_philo(t_philo **philo, t_input *input);
int		init_mutex(t_input *input);

void	*philo_thread(void *argv);
int		philo_start(t_input *input, t_philo *philo);
int		philo_action(t_input *input, t_philo *philo);

void    monitoring(t_philo *philo, t_input *input);
void	change_monitor(t_input *input);
long	eat_last_time(t_philo *philo);

long	last_eat(t_input *input, t_philo *philo);
void	checker(t_input *input, t_philo *philo);
int		checking(t_input *input);
int		printer(t_input *input, t_philo *philo, int id, char *msg);
void	killer(t_input *input, t_philo *philo, int error_code);

void	time_wasted(long wait_time, t_input *input);
long	time_get(void);

int		ft_atoi(const char *str);

#endif