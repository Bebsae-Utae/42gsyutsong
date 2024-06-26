/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:18:58 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/26 11:15:47 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_handler(int signal)
{
	static int	bit;
	static char	temp;

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
