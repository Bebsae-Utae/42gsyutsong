/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:32:53 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/11 18:34:04 by yutsong          ###   ########.fr       */
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
		print_error(1, par);
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

void	read_map(t_param *par, char *argv)
{
	char	*line;
	int		fd;
	int		len;

	len = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		print_error(7, par);
	line = get_next_line(fd);
	len = ft_strlen(line);
	par->win_width = len - 1;
	par->mapdatas = ft_strdup(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			par->mapdatas = ft_strjoin(par->mapdatas, line);
		par->win_height ++;
	}
	free(line);
	close(fd);
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
	int		idx;
	int		cnt_dorong;
	int		cnt_item;
	int		cnt_door;

	idx = 0;
	cnt_dorong = 0;
	cnt_item = 0;
	cnt_door = 0;
	if (par->win_height * par->win_width != ft_strlen(par->newmap))
		print_error(2, par);
	while (idx ++ < ft_strlen(par->newmap))
	{
		if (par->newmap[idx] == 'E')
			cnt_door ++;
		else if (par->newmap[idx] == 'P')
			cnt_dorong ++;
		else if (par->newmap[idx] == 'C')
			cnt_item ++;
	}
	check_map2(par, cnt_dorong, cnt_item, cnt_door);
	find_dorong(par);
	if (!valid_path(par))
		print_error(9, par);
}
