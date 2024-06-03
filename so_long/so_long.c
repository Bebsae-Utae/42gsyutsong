/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:32:31 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/03 15:43:00 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *newmap)
{
	int	len;

	len = 0;
	while (newmap[len])
		len ++;
	return (len);
}

int	num_len(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len ++;
		num *= -1;
	}
	while (num)
	{
		num /= 10;
		len ++;
	}
	return (len);
}

char	*reverse_str(char *str)
{
	char	temp;
	int		idx;
	int		len;

	idx = 0;
	len = ft_strlen(str) - 1;
	while (idx < len)
	{
		temp = str[idx];
		str[idx] = str[len];
		str[len] = temp;
		idx ++;
		len --;
	}
	return (str);
}

char	*int_to_char(long num)
{
	char	*str;
	long	nb;
	int		len;
	int		idx;

	idx = 0;
	len = num_len(num);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	nb = num;
	if (num == 0)
		str[idx ++] = '0';
	if (num < 0)
		nb = -nb;
	while (nb != 0)
	{
		str[idx ++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (num < 0)
		str[idx ++] = '-';
	str[idx] = '\0';
	str = reverse_str(str);
	return (str);
}

int	main(int argc, char *argv[])
{
	t_param	par;
	int		fd;

	if (argc != 2)
	{
		print_error(6);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error(7);
	set_param(&par);
	par.win = mlx_new_window(par.mlx, 640, 384, "dorong");
	read_map(&par, fd);
	check_map(&par);
	check_wall(&par);
	mlx_hook(par.win, 2, 1L << 0, &push_btn, &par);
	mlx_hook(par.win, 17, 1L << 17, &exit_btn, &par);
	printer(&par);
	mlx_loop(par.mlx);
}
