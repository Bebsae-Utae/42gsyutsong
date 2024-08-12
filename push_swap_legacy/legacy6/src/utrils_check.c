/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utrils_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:54:14 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/10 17:15:57 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_args(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j] != '\0'))
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				j ++;
				if (!ft_isdigit(argv[i][j]))
					return (false);
			}
			else if (ft_isdigit(argv[i][j]))
			{
				j ++;
				if (argv[i][j] == '\0')
					break ;
				if (!ft_isdigit(argv[i][j] && !is_space(argv[i][j])))
					return (false);
			}
			j ++;
		}
		i ++;
	}
	return (true);
}

void	check_alpha(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isalpha(argv[i][j]))
				print_error();
			j ++;
		}
		i ++;
	}
}

int	check_args2(char **argv)
{
	check_alpha(argv);
	if (!check_args(argv, 1, 0))
		return (false);
	return (true);
}

t_stack	*ft_sub_process(char **argv)
{
	t_stack	*a;
	char	**temp;
	int		idx;
	int		jdx;

	a = NULL;
	idx = 0;
	temp = ft_split(argv[1], 32);
	while (temp[idx])
	{
		jdx = ft_atoll(temp[idx]);
		list_add_back(&a, stack_init(jdx));
		idx ++;
	}
	free_str(temp);
	free(temp);
	return (a);
}

t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		print_error();
	if (argc == 2)
		a = ft_sub_process(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoll(argv[i]);
			list_add_back(&a, stack_init(j));
			i++;
		}
	}
	return (a);
}
