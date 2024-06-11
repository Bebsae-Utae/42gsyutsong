/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:10:41 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/11 16:12:52 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *dest, int val, int n)
{
	int		i;
	char	*d;

	d = (char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = (unsigned char)val;
		i++;
	}
	return (dest);
}
