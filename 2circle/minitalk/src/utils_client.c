/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:14:58 by yutsong           #+#    #+#             */
/*   Updated: 2024/07/09 13:18:14 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_send_bit(int pid, char input)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((input & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

void	client_send_str(int pid, char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		client_send_bit(pid, input[i]);
		i++;
	}
	client_send_bit(pid, '\n');
	client_send_bit(pid, '\0');
}
