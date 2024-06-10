/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:20:53 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/10 12:23:15 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map2(t_param *par, int dorong, int item, int door)
{
	if (door == 0)
		print_error(3, par);
	else if (dorong != 1)
		print_error(4, par);
	else if (item == 0)
		print_error(5, par);
	par->cnt_door = door;
	par->cnt_dorong = dorong;
	par->cnt_item = item;
}
