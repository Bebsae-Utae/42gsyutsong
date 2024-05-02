/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:54:41 by yutsong           #+#    #+#             */
/*   Updated: 2024/05/02 16:00:39 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr_fd(147483648);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-'),
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10);
		ft_putchar((n % 10) + 48);
		return ;
	}
	ft_putchar(n + 48);
}


int	print_d(va_list args)
{
	int				nb;
	unsigned int	i;

	nb = va_arg(args, int);
	i = 1;
	if (nb < 0 && nb != -2147483648)
	{
		nb = -nb;
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	ft_putnbr_fd(nb);
	if (nb == -2147483648)
		return (11);
	return (i);
}
