/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:11:10 by yutsong           #+#    #+#             */
/*   Updated: 2024/03/13 11:22:13 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_int(int n)
{
	size_t	idx;

	idx = 0;
	if (n <= 0)
		idx ++;
	while (n)
	{
		idx ++;
		n /= 10;
	}
	return (idx);
}

char	*ft_itoa(int n)
{
	char	*c;
	size_t	count;
	long	nb;

	count = count_int(n);
	nb = n;
	c = (char *)malloc((count + 1) * sizeof(char));
	if (!c)
		return (NULL);
	if (nb < 0)
	{
		*c = '-';
		nb *= (-1);
	}
	if (nb == 0)
		*c = '0';
	c[count --] = '\0';
	while (nb)
	{
		*(c + count) = nb % 10 + '0';
		count --;
		nb /= 10;
	}
	return (c);
}
