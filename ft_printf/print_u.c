/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:48:06 by yutsong           #+#    #+#             */
/*   Updated: 2024/05/02 15:48:56 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printout(unsigned int nb)
{
	if (nb > 9)
	{
		printout(nb);
		while (nb > 9)
		{
			nb = nb / 10;
		}
	}
	if (nb <= 9)
	{
		ft_putchar(nb + 48);
		return ;
	}
	ft_putchar((nb % 10) + 48);
}

int print_u(va_list args)
{
	int idx;
	unsigned int num;

	num = va_arg(args, unsigned int);
	printout(num);
	idx = 1;
	while (num > 9)
	{
		num = num / 10;
		idx++;
	}
	return (idx);
}