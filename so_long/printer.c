/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:51:13 by yutsong           #+#    #+#             */
/*   Updated: 2024/05/30 16:55:38 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void printer(t_param *par)
{
    int len;

    len = num_len(par->cnt_work);
    write(1, "movement : ", 11);
    write(1, int_to_char(par->cnt_work), len);
    write(1, "\n", 1);
    mlx_string_put(par->mlx, par->win, 20, 10, 0x00FFFFFF, "movement : ");
	mlx_string_put(par->mlx, par->win, 90, 10, 0x00FFFFFF, int_to_char(par->cnt_work));
	mlx_string_put(par->mlx, par->win, 20, 20, 0x00FFFFFF, "itemcnts : ");
	mlx_string_put(par->mlx, par->win, 90, 20, 0x00FFFFFF, int_to_char(par->get_item));
}