/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:38:52 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/13 16:39:09 by yutsong          ###   ########.fr       */
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
		j = ft_atoll_for_one(tmp[i], tmp);
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
			parse_sup(argv, &a, i);
			i++;
		}
	}
	return (a);
}

void	parse_sup(char **argv, t_stack **a, int i)
{
	char	**tmp;
	int		k;
	int		j;

	tmp = ft_split(argv[i], 32);
	k = 0;
	while (tmp[k])
	{
		j = ft_atoll_for_many(tmp[k], *a, tmp);
		stack_add_last(a, stack_init(j));
		k ++;
	}
	freezer(tmp);
}
