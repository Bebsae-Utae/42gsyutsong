/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:18:58 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/24 21:08:43 by yutsong          ###   ########.fr       */
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
		if ((input & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

void	signal_send_str(int pid, char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		signal_send_bit(pid, input[i]);
		i++;
	}
	signal_send_bit(pid, '\n');
	signal_send_bit(pid, '\0');
}
