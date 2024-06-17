/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:21:59 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/17 13:25:43 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	command()
{
	if (ft_strncmp("pa\n") == 0) return push();
	if (ft_strncmp("pb\n") == 0) return push();
	if (ft_strncmp("sa\n") == 0) return swap();
	if (ft_strncmp("sb\n") == 0) return swap();
	if (ft_strncmp("ss\n") == 0) return swap() && swap();
	if (ft_strncmp("ra\n") == 0) return rotate();
	if (ft_strncmp("rb\n") == 0) return rotate();
	if (ft_strncmp("rr\n") == 0) return rotate() && rotate();
	if (ft_strncmp("rra\n") == 0) return rotate();
	if (ft_strncmp("rrb\n") == 0) return rotate();
	if (ft_strncmp("rrr\n") == 0) return rotate() && rotate();
	print_error();
	exit(-1);
}