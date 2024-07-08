/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:28:09 by yutsong           #+#    #+#             */
/*   Updated: 2024/07/08 16:04:28 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_btn(t_param *par)
{
	mlx_destroy_window(par->mlx, par->win);
	exit(0);
	free(par->newmap);
}

int	clear_game(t_param *par)
{
	mlx_destroy_window(par->mlx, par->win);
	write(1, "congratulation!\n", 16);
	exit(0);
}
