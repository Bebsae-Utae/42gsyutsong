/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:54:41 by yutsong           #+#    #+#             */
/*   Updated: 2024/05/07 14:46:01 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd((-n), fd);
	}
	else if (n < 10 && n >= 0)
		ft_putchar(n + '0');
	else if (n > 0)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar(n % 10 + '0');
	}
}

int	print_d(va_list args)
{
	int	nb;
	int	temp_nb;
	int	idx;

	nb = va_arg(args, int);
	temp_nb = nb;
	idx = 1;
	ft_putnbr_fd(nb, 1);
	if (temp_nb == -2147483648)
		return (11);
	if (temp_nb < 0)
	{
		temp_nb *= (-1);
		idx ++;
	}
	while (temp_nb > 9)
	{
		temp_nb /= 10;
		idx++;
	}
	return (idx);
}
