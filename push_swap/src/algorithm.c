/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:36:14 by yogun             #+#    #+#             */
/*   Updated: 2024/08/08 18:31:10 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoll(const char *str)
{
	int				minus;
	long long int	result;

	result = 0;
	minus = 1;
	while (is_space(str))
		str++;
	if (*str == '-')
	{
		minus *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			print_error();
		result = result * 10 + (*str - 48);
		str++;
	}
	if ((minus * result) > 2147483647 || (minus * result) < -2147483648)
		print_error();
	return (minus * result);
}

// This function works and sorts the stacks
// in case of they are passed in between quotation
// marks. In this scenario, this function takes the
// string, and splits the numbers in order to create
// seperated integer number.
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
		ft_add_back(&a, ft_stack_new(jdx));
		idx ++;
	}
	ft_freestr(temp);
	free(temp);
	return (a);
}

// This function does three things.
// 1. It checks if the number of input is less than 2.
// 2. It checks if the number of input is equal to 2.
//    If it is, it means it is a quoted string. Call
//	  another function. <ft_sub_process>
// 3. It checks if the number of input is greater than 2.
//     If it is, it lists the arguements.
t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = ft_sub_process(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi2(argv[i]);
			ft_add_back(&a, ft_stack_new(j));
			i++;
		}
	}
	return (a);
}
