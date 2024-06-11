/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dorong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:36:54 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/11 13:38:17 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_a(t_param *par)
{
	find_dorong(par);
	if (par->newmap[par->where_dorong - 1] == 'E'
		&& par->get_item == par->cnt_item)
	{
		par->cnt_work ++;
		clear_game(par);
	}
	else if (par->newmap[par->where_dorong - 1] != '1'
		&& par->newmap[par->where_dorong - 1] != 'E')
	{
		par->cnt_work ++;
		if (par->newmap[par->where_dorong - 1] == 'C')
			par->get_item ++;
		mlx_clear_window(par->mlx, par->win);
		par->newmap[par->where_dorong] = '0';
		par->newmap[par->where_dorong - 1] = 'P';
		draw_map(par);
		printer(par);
	}
}

void	move_d(t_param *par)
{
	find_dorong(par);
	if (par->newmap[par->where_dorong + 1] == 'E'
		&& par->get_item == par->cnt_item)
	{
		par->cnt_work ++;
		clear_game(par);
	}
	else if (par->newmap[par->where_dorong + 1] != '1'
		&& par->newmap[par->where_dorong + 1] != 'E')
	{
		par->cnt_work ++;
		if (par->newmap[par->where_dorong + 1] == 'C')
			par->get_item ++;
		mlx_clear_window(par->mlx, par->win);
		par->newmap[par->where_dorong] = '0';
		par->newmap[par->where_dorong + 1] = 'P';
		draw_map(par);
		printer(par);
	}
}

void	move_s(t_param *par)
{
	find_dorong(par);
	if (par->newmap[par->where_dorong + par->win_width] == 'E'
		&& par->get_item == par->cnt_item)
	{
		par->cnt_work ++;
		clear_game(par);
	}
	else if (par->newmap[par->where_dorong + par->win_width] != '1'
		&& par->newmap[par->where_dorong + par->win_width] != 'E')
	{
		par->cnt_work ++;
		if (par->newmap[par->where_dorong + par->win_width] == 'C')
			par->get_item ++;
		mlx_clear_window(par->mlx, par->win);
		par->newmap[par->where_dorong] = '0';
		par->newmap[par->where_dorong + par->win_width] = 'P';
		draw_map(par);
		printer(par);
	}
}

void	move_w(t_param *par)
{
	find_dorong(par);
	if (par->newmap[par->where_dorong - par->win_width] == 'E'
		&& par->get_item == par->cnt_item)
	{
		par->cnt_work ++;
		clear_game(par);
	}
	else if (par->newmap[par->where_dorong - par->win_width] != '1'
		&& par->newmap[par->where_dorong - par->win_width] != 'E' )
	{
		par->cnt_work ++;
		if (par->newmap[par->where_dorong - par->win_width] == 'C')
			par->get_item ++;
		mlx_clear_window(par->mlx, par->win);
		par->newmap[par->where_dorong] = '0';
		par->newmap[par->where_dorong - par->win_width] = 'P';
		draw_map(par);
		printer(par);
	}
}

int	push_btn(int keycode, t_param *par)
{
	if (keycode == KEY_A)
		move_a(par);
	else if (keycode == KEY_D)
		move_d(par);
	else if (keycode == KEY_S)
		move_s(par);
	else if (keycode == KEY_W)
		move_w(par);
	else if (keycode == KEY_ESC)
		exit_btn(par);
	return (0);
}
