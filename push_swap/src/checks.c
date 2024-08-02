/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:37:39 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/02 16:11:35 by yutsong          ###   ########.fr       */
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
			print_error(1);
		if (check_equal(temp, args, idx))
			print_error(1);
		if (temp < -2147483648 || temp > 2147483647)
			print_error(1);
		idx ++;
	}
	if (argc == 2)
		free_all(args);
}

int	check_equal(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}