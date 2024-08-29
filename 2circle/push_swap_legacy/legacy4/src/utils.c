/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:25:53 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/06 14:58:23 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int		idx;
	int		minus;
	long	result;

	idx = 0;
	minus = 1;
	result = 0;
	while (str[idx] >= 7 && str[idx] <= 13)
		idx ++;
	if (str[idx] == '-')
	{
		minus *= -1;
		idx ++;
	}
	while (ft_isdigit(str[idx]))
	{
		result = result * 10 + (str[idx] - '0');
		idx ++;
	}
	return (result * minus);
}

int	ft_strlcpy(char *dest, const char *src, int size)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(src);
	if (!size)
		return (len);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (len);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}
