/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:28:09 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/08 19:44:58 by yutsong          ###   ########.fr       */
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
	free(par->mapdatas);
	free(par->mlx);
	exit(1);
}

void	clear_game(t_param *par)
{
	write(1, "congratulation!\n", 16);
	exit_btn(par);
}

int	exit_pre(t_param *par)
{
	write(1, "Error\n", 6);
	write(1, "File not exist.\n", 16);
	mlx_destroy_image(par->mlx, par->tree);
	mlx_destroy_image(par->mlx, par->dorong);
	mlx_destroy_image(par->mlx, par->tile);
	mlx_destroy_image(par->mlx, par->item);
	mlx_destroy_image(par->mlx, par->door);
	mlx_destroy_display(par->mlx);
	free(par->mlx);
	exit(1);
}

int	exit_sur(t_param *par)
{
	write(1, "Error\nNot Surrounded.\n", 22);
	mlx_destroy_image(par->mlx, par->tree);
	mlx_destroy_image(par->mlx, par->dorong);
	mlx_destroy_image(par->mlx, par->tile);
	mlx_destroy_image(par->mlx, par->item);
	mlx_destroy_image(par->mlx, par->door);
	mlx_destroy_window(par->mlx, par->win);
	mlx_destroy_display(par->mlx);
	free(par->mapdatas);
	free(par->mlx);
	exit(1);
}
