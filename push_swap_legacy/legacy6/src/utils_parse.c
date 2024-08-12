/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:56:31 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/10 17:19:43 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*parse_check(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc < 2)
		print_error();
	else if (argc == 2)
		a = parse_args(argv);
	else
		list_add_args(argv, &a);
	return (a);
}

t_stack	*parse_args(char **argv)
{
	t_stack	*a;
	char	**temp;

	a = NULL;
	temp = ft_split(argv[1], 32);
	list_add_args(temp, &a);
	free_str(temp);
	free(temp);
	return (a);
}