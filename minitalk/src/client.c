/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:45:23 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/25 11:35:29 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char **argv)
{
	int	pid;

	if (argc == 3 && argv[2][0] != '\0')
	{
		pid = ft_atoi(argv[1]);
		if (pid < 100 || pid > 4194304)
		{
			ft_putstr_fd("Invalid PID.\n", 1);
			return (0);
		}
		signal_send_str(pid, argv[2]);
	}
	else
		ft_putstr_fd("Wrong Arguments.\n", 1);
	return (0);
}