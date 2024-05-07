/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:48:06 by yutsong           #+#    #+#             */
/*   Updated: 2024/05/07 14:06:27 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_nbr_unsigned(unsigned int num)
{
	if (num > 9)
		put_nbr_unsigned(num / 10);
	if (num <= 9)
	{
		ft_putchar(num + 48);
		return ;
	}
	ft_putchar((num % 10) + 48);
}

int	print_u(va_list args)
{
	int				idx;
	unsigned int	num;

	num = va_arg(args, unsigned int);
	put_nbr_unsigned(num);
	idx = 1;
	while (num > 9)
	{
		num = num / 10;
		idx++;
	}
	return (idx);
}
