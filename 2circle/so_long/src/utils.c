/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:55:32 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/11 14:23:41 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *newmap)
{
	int	len;

	len = 0;
	while (newmap[len])
		len ++;
	return (len);
}

int	num_len(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len ++;
		num *= -1;
	}
	while (num)
	{
		num /= 10;
		len ++;
	}
	return (len);
}

char	*reverse_str(char *str)
{
	char	temp;
	int		idx;
	int		len;

	idx = 0;
	len = ft_strlen(str) - 1;
	while (idx < len)
	{
		temp = str[idx];
		str[idx] = str[len];
		str[len] = temp;
		idx ++;
		len --;
	}
	return (str);
}

char	*int_to_char(long num)
{
	char	*str;
	long	nb;
	int		len;
	int		idx;

	idx = 0;
	len = num_len(num);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	nb = num;
	if (num == 0)
		str[idx ++] = '0';
	if (num < 0)
		nb = -nb;
	while (nb != 0)
	{
		str[idx ++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (num < 0)
		str[idx ++] = '-';
	str[idx] = '\0';
	str = reverse_str(str);
	return (str);
}

char	*ft_strnstr(char *big, char *little, int len)
{
	int	i;
	int	j;

	i = 0;
	if (*little == '\0')
		return ((char *) big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
