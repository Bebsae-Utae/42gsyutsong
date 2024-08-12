/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:14:22 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/24 17:15:46 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int argc, char **argv)
{
	int		idx;
	long	temp;
	char	**args;	

	idx = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		idx = 1;
		args = argv;
	}
	while (args[idx])
	{
		temp = ft_atoi(args[idx]);
		if (!ft_isnum(args[idx]))
			ft_error("Error");
		if (ft_contains(temp, args, idx))
			ft_error("Error");
		if (temp < -2147483648 || temp > 2147483647)
			ft_error("Error");
		idx++;
	}
	if (argc == 2)
		ft_free(args);
}