/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:28:09 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/01 15:11:39 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_btn(t_param *par)
{
	mlx_loop_end(par->mlx);
	mlx_destroy_image(par->mlx, par->tree);
	mlx_destroy_image(par->mlx, par->dorong);
	mlx_destroy_image(par->mlx, par->tile);
	mlx_destroy_image(par->mlx, par->item);
	mlx_destroy_image(par->mlx, par->door);
	mlx_destroy_window(par->mlx, par->win);
	mlx_destroy_display(par->mlx);
	free(par->newmap);
	free(par->mlx);
	free(par->mapdatas);
	exit(0);
}

int	clear_game(t_param *par)
{
	exit_btn(par);
	write(1, "congratulation!\n", 16);
	exit(0);
}
