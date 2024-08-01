/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:20:53 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/01 14:57:17 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map2(t_param *par, int dorong, int item, int door)
{
	if (door != 1)
		print_error(3, par);
	else if (dorong != 1)
		print_error(4, par);
	else if (item == 0)
		print_error(5, par);
	par->cnt_door = door;
	par->cnt_dorong = dorong;
	par->cnt_item = item;
}

void	check_rec(t_param *par)
{
	int	idx;
	int	len;

	len = 0;
	idx = 0;
	while (par->mapdatas[idx])
	{
		if (par->mapdatas[idx] == '\n')
		{
			if (len != par->win_width)
				print_error(2, par);
			len = 0;
			idx ++;
		}
		len ++;
		idx ++;
	}
}

void	check_mapname(t_param *par, char *filename)
{
	char	*temp;

	temp = ft_strnstr(filename, ".ber", ft_strlen(filename));
	if (temp == NULL || ft_strlen(temp) > 4)
		print_error(8, par);
}

int	dfs(t_param *par, int idx, int width, int height)
{
	if (idx < 0 || idx >= width * height
		|| par->newmap[idx] == '1' || par->visited[idx])
		return (0);
	par->visited[idx] = 1;
	if (par->newmap[idx] == 'E')
		return (1);
	if (idx % width != 0 && dfs(par, idx - 1, width, height))
		return (1);
	if ((idx + 1) % width != 0 && dfs(par, idx + 1, width, height))
		return (1);
	if (idx - width >= 0 && dfs(par, idx - width, width, height))
		return (1);
	if (idx + width < width * height
		&& dfs(par, idx + width, width, height))
		return (1);
	return (0);
}

int	valid_path(t_param *par)
{
	int	result;

	par->visited
		= (int *)malloc(par->win_width * par->win_height * sizeof(int));
	if (!par->visited)
		return (0);
	ft_memset(par->visited, 0, par->win_width * par->win_height * sizeof(int));
	result = dfs(par, par->where_dorong, par->win_width, par->win_height);
	free(par->visited);
	return (result);
}
