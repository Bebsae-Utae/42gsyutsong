/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:41:32 by yutsong           #+#    #+#             */
/*   Updated: 2024/05/07 14:04:40 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(va_list args)
{
	char	*data;
	int		idx;

	idx = 0;
	data = va_arg(args, char *);
	if (!data)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (data[idx])
	{
		write(1, &data[idx], 1);
		idx ++;
	}
	return (idx);
}
