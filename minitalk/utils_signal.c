/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:18:58 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/24 20:36:00 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int signal)
{
	int		bit;
	char	temp;

	if (signal == SIGUSR1)
		temp |= (1 << bit);
	bit ++;
	if (bit == 8)
	{
		ft_putchar_fd(temp, 1);
		bit = 0;
		temp = 0;
	}
}

void	signal_send_bit(int pid, char input)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
    	// 가장 오른쪽 비트부터 왼쪽으로 가면서 전송함
        // 1을 bit만큼 left shift 연산 한 값을 input과 &연산
		if ((input & (1 << bit)) != 0)
			kill(pid, SIGUSR1); // 해당 값이 1일 경우 SIGUSR1 신호 전송
		else
			kill(pid, SIGUSR2); // 해당 값이 0일 경우 SIGUSR2 신호 전송
		usleep(100); // 딜레이를 위해
		bit++;
	}
}

void	signal_send_str(int pid, char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0') // 한 문자씩 전송함
	{
		signal_send_bit(pid, input[i]);
		i++;
	}
	signal_send_bit(pid, '\n');
	signal_send_bit(pid, '\0'); // 문자열 전송을 끝냈다는 것을 알리기 위한 널문자 전송
}
