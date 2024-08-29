/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:41:12 by yutsong           #+#    #+#             */
/*   Updated: 2024/05/08 11:13:55 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putptr2(unsigned int ptr, char c)
{
	unsigned int	temp;

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

int	print_xx(va_list args, char c)
{
	unsigned int	ptr;
	int				idx;

	idx = 0;
	ptr = va_arg(args, unsigned int);
	if (!ptr)
	{
		write(1, "0", 1);
		return (1);
	}
	putptr2(ptr, c);
	while (ptr != 0)
	{
		idx ++;
		ptr /= 16;
	}
	return (idx);
}
