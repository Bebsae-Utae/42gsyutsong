/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:38:52 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/12 20:30:35 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*parse_check(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoll(tmp[i]);
		stack_add_last(&a, stack_init(j));
		i++;
	}
	free_str(tmp);
	free(tmp);
	return (a);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		exit_btn();
	if (argc == 2)
		a = parse_check(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoll(argv[i]);
			stack_add_last(&a, stack_init(j));
			i++;
		}
	}
	return (a);
}
