/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:21:59 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/18 16:19:26 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	command()
{
	if (ft_strncmp("pa\n") == 0) return pa();
	if (ft_strncmp("pb\n") == 0) return pb();
	if (ft_strncmp("sa\n") == 0) return sa();
	if (ft_strncmp("sb\n") == 0) return sb();
	if (ft_strncmp("ss\n") == 0) return ss();
	if (ft_strncmp("ra\n") == 0) return ra();
	if (ft_strncmp("rb\n") == 0) return rb();
	if (ft_strncmp("rr\n") == 0) return rr();
	if (ft_strncmp("rra\n") == 0) return rra();
	if (ft_strncmp("rrb\n") == 0) return rrb();
	if (ft_strncmp("rrr\n") == 0) return rrr();
	print_error();
	exit(-1);
}