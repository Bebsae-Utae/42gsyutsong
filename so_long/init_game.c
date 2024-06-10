/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:33:42 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/10 12:03:27 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_param(t_param *par)
{
	par->mlx = mlx_init();
	par->win = NULL;
	par->dorong = mlx_xpm_file_to_image(par->mlx, "img/dorong.xpm",
			&par->width, &par->height);
	par->tree = mlx_xpm_file_to_image(par->mlx, "img/tree.xpm",
			&par->width, &par->height);
	par->tile = mlx_xpm_file_to_image(par->mlx, "img/tile.xpm",
			&par->width, &par->height);
	par->item = mlx_xpm_file_to_image(par->mlx, "img/item.xpm",
			&par->width, &par->height);
	par->door = mlx_xpm_file_to_image(par->mlx, "img/door.xpm",
			&par->width, &par->height);
	par->x = 0;
	par->y = 0;
	par->where_dorong = 0;
	par->width = 0;
	par->height = 0;
	par->win_width = 0;
	par->win_height = 0;
	par->cnt_door = 0;
	par->cnt_dorong = 0;
	par->cnt_item = 0;
	par->cnt_work = 0;
	par->get_item = 0;
}

void	find_dorong(t_param *par)
{
	int	idx;
	int	here;

	idx = 0;
	here = 0;
	while (par->newmap[idx])
	{
		if (par->newmap[idx] == 'P')
		{
			here = idx;
			break ;
		}
		idx ++;
	}
	par->where_dorong = here;
}
