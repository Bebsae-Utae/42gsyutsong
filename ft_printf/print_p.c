/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:00:20 by yutsong           #+#    #+#             */
/*   Updated: 2024/05/02 15:34:34 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int putptr(unsigned long long ptr)
{
	int idx;
	unsigned long long temp;

	idx = 0;
	if (ptr >= 16)
	{
		putptr(ptr / 16);
		putptr(ptr % 16);
		idx ++;
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
			temp = ptr - 10 + 'a';
			ft_putchar(temp);
		}
		idx ++;
	}
	return (idx);
}

int print_p(va_list args)
{
	unsigned long long ptr;
	int idx;

	idx = 0;
	ptr = va_arg(args, unsigned long long);
	write(1, "0x", 2);
	idx += 2;
	idx += putptr(ptr);
	return (idx);
}