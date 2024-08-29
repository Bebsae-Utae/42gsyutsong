/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:48:52 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/05 18:49:11 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	dfs_c(t_param *par, int idx, int width, int height)
{
	int	count;

	count = 0;
	if (idx < 0 || idx >= width * height
		|| par->newmap[idx] == '1' || par->visited[idx])
		return (0);
	par->visited[idx] = 1;
	if (par->newmap[idx] == 'C')
		count = 1;
	if (idx % width != 0)
		count += dfs_c(par, idx - 1, width, height);
	if ((idx + 1) % width != 0)
		count += dfs_c(par, idx + 1, width, height);
	if (idx - width >= 0)
		count += dfs_c(par, idx - width, width, height);
	if (idx + width < width * height)
		count += dfs_c(par, idx + width, width, height);
	return (count);
}

int	count_total_c(char *map, int width, int height)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < width * height)
	{
		if (map[i] == 'C')
			count++;
		i++;
	}
	return (count);
}

int	valid_path(t_param *par)
{
	int	result;
	int	is_c;
	int	is_e;
	int	total_c;

	result = 1;
	par->visited
		= (int *)malloc(par->win_width * par->win_height * sizeof(int));
	if (!par->visited)
		return (0);
	ft_memset(par->visited, 0, par->win_width * par->win_height * sizeof(int));
	total_c = count_total_c(par->newmap, par->win_width, par->win_height);
	is_c = dfs_c(par, par->where_dorong, par->win_width, par->win_height);
	ft_memset(par->visited, 0, par->win_width * par->win_height * sizeof(int));
	is_e = dfs(par, par->where_dorong, par->win_width, par->win_height);
	if (is_c != total_c || !is_e)
		result = 0;
	free(par->visited);
	return (result);
}
