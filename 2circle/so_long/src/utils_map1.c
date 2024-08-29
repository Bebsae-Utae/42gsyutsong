/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:20:53 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/05 18:49:14 by yutsong          ###   ########.fr       */
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
