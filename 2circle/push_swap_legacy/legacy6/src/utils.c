/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:04:09 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/10 17:23:24 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoll(const char *str)
{
	int				minus;
	long long int	result;

	result = 0;
	minus = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		minus *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			print_error();
		result = result * 10 + (*str - 48);
		str++;
	}
	if ((minus * result) > 2147483647 || (minus * result) < -2147483648)
		print_error();
	return (minus * result);
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
