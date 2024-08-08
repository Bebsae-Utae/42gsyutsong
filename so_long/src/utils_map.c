/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:32:53 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/08 19:44:41 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_param *par)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	mlx_clear_window(par->mlx, par->win);
	while (par->newmap[i])
	{
		x = 0 + (i % par->win_width) * 64;
		y = 0 + (i / par->win_width * 64);
		if (par->newmap[i] == '1')
			mlx_put_image_to_window(par->mlx, par->win, par->tree, x, y);
		else if (par->newmap[i] == '0')
			mlx_put_image_to_window(par->mlx, par->win, par->tile, x, y);
		else if (par->newmap[i] == 'P')
			mlx_put_image_to_window(par->mlx, par->win, par->dorong, x, y);
		else if (par->newmap[i] == 'C')
			mlx_put_image_to_window(par->mlx, par->win, par->item, x, y);
		else if (par->newmap[i] == 'E')
			mlx_put_image_to_window(par->mlx, par->win, par->door, x, y);
		else
			print_error(6, par);
		i ++;
	}
}

void	make_map(t_param *par)
{
	int	idx1;
	int	idx2;
	int	len;

	idx1 = 0;
	idx2 = 0;
	if (par->win_width < 3 || par->win_height < 3)
		exit_sur(par);
	len = ft_strlen(par->mapdatas);
	par->newmap = (char *)malloc(sizeof(char) * len + 1);
	while (par->mapdatas[idx1])
	{
		if (par->mapdatas[idx1] == '\n')
			idx1 ++;
		par->newmap[idx2] = par->mapdatas[idx1];
		idx1 ++;
		idx2 ++;
	}
	par->newmap[idx2] = '\0';
}

void	check_wall(t_param *par)
{
	int	idx;

	idx = 0;
	while (idx < ft_strlen(par->newmap))
	{
		if (idx < par->win_width)
		{
			if (par->newmap[idx] != '1')
				print_error(1, par);
		}
		else if (idx % par->win_width == 0
			|| idx % par->win_width == par->win_width - 1)
		{
			if (par->newmap[idx] != '1')
				print_error(1, par);
		}
		else if (idx > ft_strlen(par->newmap) - par->win_width)
		{
			if (par->newmap[idx] != '1')
				print_error(1, par);
		}
		idx ++;
	}
}

void	check_map(t_param *par)
{
	if (par->win_height * par->win_width != ft_strlen(par->newmap))
		print_error(2, par);
	check_char(par);
	find_dorong(par);
	if (!valid_path(par))
		print_error(9, par);
}
