/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:51:13 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/05 17:20:20 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printer(t_param *par)
{
	int		len;
	char	*str;

	len = num_len(par->cnt_work);
	write(1, "movement : ", 11);
	str = int_to_char(par->cnt_work);
	write(1, str, len);
	free(str);
	write(1, "\n", 1);
	mlx_string_put(par->mlx, par->win, 20, 10, 0x00FFFFFF, "movement : ");
	str = int_to_char(par->cnt_work);
	mlx_string_put(par->mlx, par->win, 90, 10, 0x00FFFFFF,
		str);
	free(str);
	mlx_string_put(par->mlx, par->win, 20, 20, 0x00FFFFFF, "itemcnts : ");
	str = int_to_char(par->get_item);
	mlx_string_put(par->mlx, par->win, 90, 20, 0x00FFFFFF,
		str);
	free(str);
}

void	print_error(int codes, t_param *par)
{
	write(1, "Error\n", 6);
	if (codes == 1)
		write(1, "Not Surrounded.\n", 16);
	else if (codes == 2)
		write(1, "Not Rectangle.\n", 15);
	else if (codes == 3)
		write(1, "No Exit.\n", 9);
	else if (codes == 4)
		write(1, "No Player.\n", 11);
	else if (codes == 5)
		write(1, "No Item.\n", 9);
	else if (codes == 6)
		write(1, "Cannot open map.\n", 17);
	else if (codes == 7)
		write(1, "File not exist.\n", 16);
	else if (codes == 8)
		write(1, "Incorrect Filename.\n", 20);
	else if (codes == 9)
		write(1, "Invalid Path.\n", 14);
	exit_btn(par);
}
