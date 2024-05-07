/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:41:12 by yutsong           #+#    #+#             */
/*   Updated: 2024/05/07 14:41:14 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_xx(va_list args, char c)
{
	unsigned long long	ptr;
	int					idx;

	idx = 0;
	ptr = va_arg(args, unsigned long long);
	if (!ptr)
	{
		write(1, "0", 1);
		return (1);
	}
	putptr(ptr, idx, c);
	while (ptr != 0)
	{
		idx ++;
		ptr /= 16;
	}
	return (idx);
}
