/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:37:39 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/06 16:05:15 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int argc, char **argv)
{
	int		idx;
	long	temp;
	char	**args;
	char	**split_args;
	int		j, k, i;
	int		total_words;

	idx = 0;
	split_args = NULL;
	if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
	{
        if (argc > 1) {
            total_words = 0;
            j = 1;
            while (j < argc)
			{
                total_words += counter_word(argv[j], ' ');
                j++;
            }
            args = (char **)malloc((total_words + 1) * sizeof(char *));
            i = 0;
            j = 1;
            while (j < argc)
			{
                split_args = ft_split(argv[j], ' ');
                k = 0;
                while (split_args[k])
				{
                    args[i++] = split_args[k];
                    k++;
                }
                free(split_args);
                j++;
            }
            args[i] = NULL;
        }
		else
        	args = argv;
    }
    while (args[idx])
	{
		if (ft_strlen(args[idx]) == 0 || !ft_isnum(args[idx]))
			print_error(1);
        temp = ft_atol(args[idx]);
        if (check_equal(temp, args, idx))
            print_error(1);
        if (temp < -2147483648 || temp > 2147483647)
            print_error(1);
        idx++;
    }
    if (argc == 2 || split_args)
        free_all(args);
}

// 	if (argc == 2)
// 		args = ft_split(argv[1], ' ');
// 	else
// 	{
// 		if (ft_strchr(argv[1]))
// 		idx = 1;
// 		args = argv;
// 	}
// 	while (args[idx])
// 	{
// 		if (!ft_isnum(args[idx]))
// 		{
// 			if (argc == 2)
// 				free_all(args);
// 			print_error(1);
// 		}
// 		temp = ft_atol(args[idx]);
// 		if (check_equal(temp, args, idx))
// 		{
// 			if (argc == 2)
// 				free_all(args);
// 			print_error(1);
// 		}
// 		if (temp < -2147483648 || temp > 2147483647)
// 		{
// 			if (argc == 2)
// 				free_all(args);
// 			print_error(1);
// 		}
// 		idx ++;
// 	}
// 	if (argc == 2)
// 		free_all(args);
// }

int	check_equal(long num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atol(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}
