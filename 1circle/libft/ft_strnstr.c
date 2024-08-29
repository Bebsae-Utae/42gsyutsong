/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:37:15 by yutsong           #+#    #+#             */
/*   Updated: 2024/03/13 15:52:03 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *target, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (!*target)
		return ((char *)src);
	while (src[i] && i < len)
	{
		k = 0;
		while (src[i + k] == target[k] && i + k < len)
		{
			k ++;
			if (!target[k])
				return ((char *)&src[i]);
		}
		i ++;
	}
	return (0);
}
