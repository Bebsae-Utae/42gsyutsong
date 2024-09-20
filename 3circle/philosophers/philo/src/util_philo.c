/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:32:13 by yutsong           #+#    #+#             */
/*   Updated: 2024/09/20 15:58:14 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_start(t_input *input, t_philo *philo)
{
	int	idx;

	idx = 0;
	// idx 값이 철학자 수만큼 증가할 때 까지 반복문 수행
	while (idx < input->count_philo)
	{
		// 쓰레드 시작 시간 할당
		philo[idx].time_start_thread = time_get();
		// 쓰레드 생성 및 아이디 부여 성공 시 return (1)
		if (pthread_create(&(philo[idx].id_thread),
				NULL, philo_thread, &(philo[idx])))
			return (1);
		idx ++;
	}
	// checker(input, philo);
	// monitoring(philo, input);
	idx = 0;
	while (idx < input->count_philo)
		pthread_join(philo[idx++].id_thread, NULL);
	return (0);
}

void	*philo_thread(void *argv)
{
	t_input	*input;
	t_philo	*philo;

	philo = argv;
	input = philo->input;
	// 짝수 철학자는 잠시 쉬게 함
	if (philo->id_philo % 2 == 0)
		usleep(1000);
	// monitor가 0일때만 반복문 돌아감
	while (!input->monitor)
	{
		// 철학자 수가 철학자 아이디수와 같거나 식사 횟수가 0이면 잠시 슬립
		if (input->count_philo - 1 == philo->id_philo
			&& philo->count_dining == 0)
			usleep(1);
		// 식사
		philo_action(input, philo);
		// 누가 죽었으면 종료
		if (checking(philo->input))
			break ;
		// count_philo가 1이면 재움
		// if (input->count_philo == 1)
		// 밥먹었으니 잘 시간
		time_wasted((long)input->time_sleep, input);
		// 전체 식사 횟수가 개별 식사 횟수와 같으면
		// if (input->count_all_dining == philo->count_dining)
		// {
		// 	input->monitor ++;
		// 	break ;
		// }
		printer(input, philo, philo->id_philo, "is sleeping");
		// 누가 죽었으면 종료
		if (checking(philo->input))
			break ;
		// 잤으면 생각해야 함
		time_wasted((long)input->time_sleep, input);
		printer(input, philo, philo->id_philo, "is thinking");
	}
	return (0);
}

int	philo_action(t_input *input, t_philo *philo)
{
	pthread_mutex_lock(&(input->mutex_fork[philo->left_fork]));
	printer(input, philo, philo->id_philo, "has taken a left fork");
	if (input->count_philo != 1)
	{
		pthread_mutex_lock(&(input->mutex_fork[philo->right_fork]));
		printer(input, philo, philo->id_philo, "has taken a right fork");
		printer(input, philo, philo->id_philo, "is eating");
		// 식사 완료 시 time_last_dining에 해당 시점 시간 할당
		philo->time_last_dining = time_get();
		printf("time in action:%ld\n", philo->time_last_dining);
		// 식사 횟수 추가
		philo->count_dining ++;
		// 식사 시간동안 시간 흘리기
		time_wasted((long)input->time_dining, input);
		pthread_mutex_unlock(&(input->mutex_fork[philo->right_fork]));
	}
	pthread_mutex_unlock(&(input->mutex_fork[philo->left_fork]));
	return (0);
}
