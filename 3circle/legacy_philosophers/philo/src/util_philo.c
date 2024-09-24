// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   util_philo.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/09/19 12:32:13 by yutsong           #+#    #+#             */
// /*   Updated: 2024/09/23 20:05:52 by yutsong          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "philo.h"

// static void	init_single_philo(t_philo *philo, int id, t_input *input)
// {
// 	philo->id_philo = id + 1;
// 	philo->left_fork = id;
// 	philo->right_fork = (id + 1) % (input->count_philo);
// 	philo->count_dining = 0;
// 	philo->time_last_dining = input->time_start;
// 	philo->input = input;
// }

// static void	take_forks(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->input->mutex_fork[philo->left_fork]);
// 	print_status(philo, "has taken a left fork");
// 	pthread_mutex_lock(&philo->input->mutex_fork[philo->right_fork]);
// 	print_status(philo, "has taken a right fork");
// }

// static void	eat(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->input->mutex_dining);
// 	print_status(philo, "is eating");
// 	philo->time_last_dining = get_time();
// 	philo->count_dining ++;
// 	usleep(philo->input->time_dining * 1000);
// 	pthread_mutex_unlock(&philo->input->mutex_dining);
// }

// static void	put_forks(t_philo *philo)
// {
// 	pthread_mutex_unlock(&philo->input->mutex_fork[philo->left_fork]);
// 	pthread_mutex_unlock(&philo->input->mutex_fork[philo->right_fork]);	
// }

// static void	sleep_and_think(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->input->mutex_time);
// 	print_status(philo, "is sleeping");
// 	usleep(philo->input->time_sleep * 1000);
// 	print_status(philo, "is thinking");
// 	pthread_mutex_unlock(&philo->input->mutex_time);
// }

// int	create_philo(t_input *input)
// {
// 	int	idx;

// 	input->philosophers = malloc(sizeof(t_philo) * (input->count_philo));
// 	if (!input->philosophers)
// 		return (1);
// 	idx = 0;
// 	while (idx < input->count_philo)
// 	{
// 		init_single_philo(&input->philosophers[idx], idx, input);
// 		if (pthread_create(&input->philosophers[idx].id_thread, NULL, philosopher_routine, &input->philosophers[idx]))
// 		{
// 			while (--idx >= 0)
// 				pthread_join(input->philosophers[idx].id_thread, NULL);
// 			free(input->philosophers);
// 			return (1);
// 		}
// 		idx ++;
// 	}
// 	return (0);
// }

// void	*philosopher_routine(void *arg)
// {
// 	t_philo	*philo;
// 	t_input	*input;

// 	philo = (t_philo *)arg;
// 	input = philo->input;
// 	if (philo->id_philo % 2 == 0)
// 		usleep(1000);
// 	while (!input->who_died)
// 	{
// 		printf("222222222222222222\n");
// 		take_forks(philo);
// 		eat(philo);
// 		put_forks(philo);
// 		sleep_and_think(philo);
// 		if (input->count_all_dining != -1 && philo->count_dining >= input->count_all_dining)
// 			break ;
// 	}
//     printf("Philosopher %d exiting loop.\n", philo->id_philo);
// 	return (NULL);
// }

// void	print_status(t_philo *philo, char *status)
// {
// 	long long	current_time;

// 	pthread_mutex_lock(&philo->input->mutex_print);
// 	if (!philo->input->who_died)
// 	{
// 		current_time = get_time() - philo->input->time_start;
// 		printf("%lld %d %s\n", current_time, philo->id_philo, status);
// 	}
// 	pthread_mutex_unlock(&philo->input->mutex_print);
// }

// // int	philo_start(t_input *input, t_philo *philo)
// // {
// // 	int	idx;

// // 	idx = 0;
// // 	// idx 값이 철학자 수만큼 증가할 때 까지 반복문 수행
// // 	while (idx < input->count_philo)
// // 	{
// // 		// 쓰레드 시작 시간 할당
// // 		philo[idx].time_start_thread = time_get();
// // 		// 쓰레드 생성 및 아이디 부여 성공 시 return (1)
// // 		if (pthread_create(&(philo[idx].id_thread),
// // 				NULL, philo_thread, &(philo[idx])))
// // 			return (1);
// // 		idx ++;
// // 		// printf("%d %d\n", idx, input->count_philo);
// // 	}
// // 	// 모니터링 스레드 생성
// // 	// if (pthread_create(&monitor_thread, NULL, (void *)monitoring, (void *)philo))
// // 	// 	return (1);
// // 	// checker(input, philo);
// // 	monitoring(philo, input);
// // 	idx = 0;
// // 	while (idx < input->count_philo)
// // 		pthread_join(philo[idx++].id_thread, NULL);
// // 	return (0);
// // }

// // void	*philo_thread(void *argv)
// // {
// // 	t_input	*input;
// // 	t_philo	*philo;
// // 	int		idx;

// // 	idx = 0;
// // 	philo = argv;
// // 	input = philo->input;
// // 	// 짝수 철학자는 잠시 쉬게 함
// // 	if (philo->id_philo % 2 == 0)
// // 		usleep(1000);
// // 	// monitor가 0일때만 반복문 돌아감
// // 	while (!input->monitor)
// // 	{
// // 		// 철학자 수가 철학자 아이디수와 같거나 식사 횟수가 0이면 잠시 슬립
// // 		if (input->count_philo - 1 == philo->id_philo
// // 			&& philo->count_dining == 0)
// // 			usleep(1);
// // 		// 식사
// // 		philo_action(input, philo);
// // 		// 누가 죽었으면 종료
// // 		printf("died:%d\n", philo->died);
// // 		if (philo->died)
// // 			break ;
// // 		// count_philo가 1이면 재움
// // 		// if (input->count_philo == 1)
// // 		// 밥먹었으니 잘 시간
// // 		time_wasted((long)input->time_sleep, input);
// // 		// 전체 식사 횟수가 개별 식사 횟수와 같으면 종료
// // 		if (input->count_all_dining == philo->count_dining)
// // 		{
// // 			change_monitor(input);
// // 			break ;
// // 		}
// // 		printer(input, philo, philo->id_philo, "is sleeping");
// // 		// 누가 죽었으면 종료
// // 		// if (checking(philo->input))
// // 		// 	break ;
// // 		// 잤으면 생각해야 함
// // 		time_wasted((long)input->time_sleep, input);
// // 		printer(input, philo, philo->id_philo, "is thinking");
// // 		idx ++;
// // 	}
// // 	return (0);
// // }

// // int	philo_action(t_input *input, t_philo *philo)
// // {
// // 	pthread_mutex_lock(&(input->mutex_fork[philo->left_fork]));
// // 	printer(input, philo, philo->id_philo, "has taken a left fork");
// // 	if (input->count_philo != 1)
// // 	{
// // 		pthread_mutex_lock(&(input->mutex_fork[philo->right_fork]));
// // 		printer(input, philo, philo->id_philo, "has taken a right fork");
// // 		printer(input, philo, philo->id_philo, "is eating");
// // 		// 식사 완료 시 time_last_dining에 해당 시점 시간 할당
// // 		philo->time_last_dining = time_get();
// // 		printf("time in action:%ld\n", philo->time_last_dining);
// // 		// 식사 횟수 추가
// // 		philo->count_dining ++;
// // 		// 식사 시간동안 시간 흘리기
// // 		time_wasted((long)input->time_dining, input);
// // 		pthread_mutex_unlock(&(input->mutex_fork[philo->right_fork]));
// // 	}
// // 	pthread_mutex_unlock(&(input->mutex_fork[philo->left_fork]));
// // 	return (0);
// // }
