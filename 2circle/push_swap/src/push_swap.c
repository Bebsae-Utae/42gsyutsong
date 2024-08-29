/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:09:10 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/12 20:30:50 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = parse_args(argc, argv);
	if (!a || is_equal(a))
	{
		free_list(&a);
		print_error();
	}
	if (!is_sorted(a))
		sort_big(&a);
	free_list(&a);
	return (0);
}
