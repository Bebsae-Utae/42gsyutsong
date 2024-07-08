/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:48:28 by yutsong           #+#    #+#             */
/*   Updated: 2024/07/08 13:54:49 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_char(t_param *par)
{
	int		idx;
	int		cnt_dorong;
	int		cnt_item;
	int		cnt_door;

	idx = 0;
	cnt_dorong = 0;
	cnt_item = 0;
	cnt_door = 0;
	while (idx ++ < ft_strlen(par->newmap))
	{
		if (par->newmap[idx] == 'E')
			cnt_door ++;
		else if (par->newmap[idx] == 'P')
			cnt_dorong ++;
		else if (par->newmap[idx] == 'C')
			cnt_item ++;
		else if (par->newmap[idx] != 0 && par->newmap[idx] != 1
			&& par->newmap[idx] != 48 && par->newmap[idx] != 49
			&& par->newmap[idx] != 67 && par->newmap[idx] != 69
			&& par->newmap[idx] != 80)
			print_error(6, par);
	}
	check_map2(par, cnt_dorong, cnt_item, cnt_door);
}
