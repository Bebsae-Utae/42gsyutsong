/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:44:11 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/01 15:44:51 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_param *par, char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		print_error(7, par);
	if (!init_map_data(par, fd))
	{
		close(fd);
		return ;
	}
	read_remaining_lines(par, fd);
	close(fd);
}

int	init_map_data(t_param *par, int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	len = ft_strlen(line);
	par->win_width = len - 1;
	par->mapdatas = ft_strdup(line);
	free(line);
	if (!par->mapdatas)
	{
		close(fd);
		return (0);
	}
	par->win_height = 1;
	return (1);
}

void	read_remaining_lines(t_param *par, int fd)
{
	char	*line;
	char	*temp;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = ft_strjoin(par->mapdatas, line);
		free(par->mapdatas);
		par->mapdatas = temp;
		free(line);
		if (!par->mapdatas)
		{
			close(fd);
			return ;
		}
		par->win_height++;
	}
}
