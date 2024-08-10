/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:04:41 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/10 20:14:10 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

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

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	inttemp;

	i = 0;
	minus = 1;
	inttemp = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i ++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			minus *= -1;
		i ++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		inttemp = inttemp * 10 + (str[i] - 48);
		i ++;
	}
	return (inttemp * minus);
}

int	ft_atoll(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			print_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		print_error();
	return (mod * i);
}