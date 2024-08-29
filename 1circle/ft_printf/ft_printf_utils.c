/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:51:27 by yutsong           #+#    #+#             */
/*   Updated: 2024/05/08 10:42:27 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putptr(unsigned long long ptr, char c)
{
	unsigned long long	temp;

	if (ptr >= 16)
	{
		putptr(ptr / 16, c);
		putptr(ptr % 16, c);
	}
	else
	{
		if (ptr < 10)
		{
			temp = '0' + ptr;
			ft_putchar(temp);
		}
		else
		{
			temp = ptr - 10 + c;
			ft_putchar(temp);
		}
	}
}
