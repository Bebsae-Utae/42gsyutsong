/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:19:28 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/10 19:30:11 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_alpha(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isalpha(argv[i][j]))
				print_error();
			j++;
		}
		i++;
	}
}

int	check_args(char **argv)
{
	check_alpha(argv);
	if (!check_error(argv, 1, 0))
		return (false);
	return (true);
}

int	check_error(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
			{
				j ++;
				if (!(argv[i][j] >= 48 && argv[i][j] <= 57))
					return (false);
			}
			else if ((argv[i][j] >= 48 && argv[i][j] <= 57))
			{
				j ++;
				if (argv[i][j] == '\0')
					break ;
				if (!(argv[i][j] >= 48 && argv[i][j] <= 57) && !(argv[i][j] == ' '))
					return (false);
			}
			j ++;
		}
		i ++;
	}
	return (true);
}
