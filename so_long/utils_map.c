/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:32:53 by yutsong           #+#    #+#             */
/*   Updated: 2024/05/30 13:54:16 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(t_param *par)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	mlx_clear_window(par->mlx, par->win);
	while (par->newmap[i])
	{
		x = 0 + (i % 10) * 64;
		y = 0 + (i / 10 * 64);
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
		i ++;
	}
}

void	make_map(t_param *par, char *mapdatas)
{
	int	idx1;
	int	idx2;
	int	len;

	idx1 = 0;
	idx2 = 0;
	len = ft_strlen(mapdatas);
	len = len - par->win_height;
	par->newmap = (char *)malloc(sizeof(char) * len + 1);
	while (mapdatas[idx1])
	{
		if (mapdatas[idx1] == '\n')
			idx1 ++;
		par->newmap[idx2] = mapdatas[idx1];
		idx1 ++;
		idx2 ++;
	}
	par->newmap[idx2] = '\0';
	draw_map(par);
}

void	read_map(t_param *par)
{
	char	*mapdatas = "1111111111\n10P1C01E11\n1011101001\n1001101101\n1100000001\n1111111111";
	// char *mapdatas = "1111111111\n1000000001\n1011101001\n1001101101\n1100000001\n1111111111";
	int		idx;

	idx = 0;
	while (mapdatas[idx])
	{
		if (mapdatas[idx] == '\n')
			par->win_height ++;
		idx ++;
	}
	idx = 0;
	while (mapdatas[idx])
	{
		if (mapdatas[idx] == '\n')
			break ;
		par->win_width ++;
		idx ++;
	}
	make_map(par, mapdatas);
}

void	check_wall(t_param *par)
{
	int	idx;

	idx = 0;
	if (idx < ft_strlen(par->newmap))
	{
		if (idx < par->win_width)
			if (par->newmap[idx] != '1')
				write(1, "Not Surrounded.\n", 16);
		else if (idx % par->win_width == 0 || idx % par->win_width == par->win_width - 1)
			if (par->newmap[idx] != '1')
				write(1, "Not Surrounded.\n", 16);
		else if (idx > ft_strlen(par->newmap) - par->win_width)
			if (par->newmap[idx] != '1')
				write(1, "Not Surrounded.\n", 16);
		idx ++;
	}
}

void	check_map(t_param *par)
{
	int		idx;
	int		cnt_dorong;
	int		cnt_item;
	int		cnt_door;
	char	c;

	idx = 0;
	cnt_dorong = 0;
	cnt_item = 0;
	cnt_door = 0;
	if ((par->win_height + 1) * par->win_width != ft_strlen(par->newmap))
		write(1, "Not Rectangle.\n", 15);
	while (idx ++ < ft_strlen(par->newmap))
	{
		if (par->newmap[idx] == 'E')
			cnt_door ++;
		else if (par->newmap[idx] == 'P')
			cnt_dorong ++;
		else if (par->newmap[idx] == 'C')
			cnt_item ++;
	}
	if (cnt_door == 0)
		write(1, "No Exit.\n", 9);
	else if (cnt_dorong != 1)
		write(1, "No Player.\n", 11);
	else if (cnt_item == 0)
		write(1, "No Item.\n", 9);
	par->cnt_door = cnt_door;
	par->cnt_dorong = cnt_dorong;
	par->cnt_item = cnt_item;
}
