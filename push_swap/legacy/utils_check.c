/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:23:41 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/18 17:31:05 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int argc, char **argv)
{
	int		idx;
	int		temp;

	idx = 1;
	if (argc <= 1)
		print_error();
	while (argv[idx])
	{
		if (!check_num(argv[idx]))
			print_error();
		temp = ft_atoi(argv[idx]);
		if (check_duplicate(temp, argv, idx))
			print_error();
		if (temp < -2147483648 || temp > 2147483647)
			print_error();
		idx ++;
	}
	if (argv == 2)
		list_free(argv);
}

int	check_num(char *num)
{
	int	idx;

	idx = 0;
	if (num[0] == '-')
		idx ++;
	while (num[idx])
	{
		if (!(num[idx] >= '0' && num[idx] <= '9'))
			return (0);
		idx ++;
	}
	return (1);
}

int	check_duplicate(int num, char **argv, int idx)
{
	idx ++;
	while (argv[idx])
	{
		if (ft_atoi(argv[idx]) == num)
			return (1);
		idx ++;
	}
	return (0);
}

int	check_sorted(t_node **stack)
{
	t_node	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}