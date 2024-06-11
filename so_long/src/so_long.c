/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:32:31 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/11 14:24:35 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_param	par;

	if (argc != 2)
	{
		print_error(6, &par);
		return (0);
	}
	set_param(&par);
	read_map(&par, argv[1]);
	par.win = mlx_new_window(par.mlx,
			par.win_width * 64, par.win_height * 64, "dorong");
	make_map(&par);
	check_mapname(&par, argv[1]);
	check_rec(&par);
	check_map(&par);
	check_wall(&par);
	draw_map(&par);
	mlx_hook(par.win, 2, 1L << 0, &push_btn, &par);
	mlx_hook(par.win, 17, 1L << 17, &exit_btn, &par);
	printer(&par);
	mlx_loop(par.mlx);
}
