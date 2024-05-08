/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:00:20 by yutsong           #+#    #+#             */
/*   Updated: 2024/05/08 10:40:57 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(va_list args)
{
	unsigned long long	ptr;
	int					idx;

	idx = 0;
	ptr = va_arg(args, unsigned long long);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	idx += 2;
	putptr(ptr, 'a');
	while (ptr != 0)
	{
		idx ++;
		ptr /= 16;
	}
	return (idx);
}
