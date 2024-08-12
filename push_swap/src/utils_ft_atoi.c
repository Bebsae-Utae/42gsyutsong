/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 23:16:59 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/12 23:17:13 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atoll(const char *str, char **tmp, int mod, long long int i)
{
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
		if (!ft_isdigit(*str))
			freeze(tmp);
	}
	else if (*str == '+')
	{
		str ++;
		if (*str == '+' || *str == '\0')
			freeze(tmp);
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			freeze(tmp);
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		freeze(tmp);
	return (mod * i);
}

long	ft_atoll_for_one(const char *str, char **tmp)
{
	int				mod;
	long long int	i;
	int				result;

	i = 0;
	mod = 1;
	result = ft_atoll(str, tmp, mod, i);
	return (result);
}

long	ft_atoll2(const char *str, t_stack *a, int mod, long long int i)
{
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
		if (!ft_isdigit(*str))
			freedom(a);
	}
	else if (*str == '+')
		str ++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			freedom(a);
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		freedom(a);
	return (mod * i);
}

long	ft_atoll_for_many(const char *str, t_stack *a)
{
	int				mod;
	long long int	i;
	int				result;

	i = 0;
	mod = 1;
	result = ft_atoll2(str, a, mod, i);
	return (result);
}
