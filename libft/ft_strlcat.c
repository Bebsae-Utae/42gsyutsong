/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:12:38 by yutsong           #+#    #+#             */
/*   Updated: 2024/03/15 14:30:57 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_i;
	size_t	src_i;
	size_t	idx;

	idx = 0;
	dest_i = ft_strlen(dest);
	src_i = ft_strlen(src);
	if (size <= dest_i)
		return (src_i + size);
	while (src[idx] && dest_i + idx + 1 < size)
	{
		dest[dest_i + idx] = src[idx];
		idx ++;
	}
	dest[dest_i + idx] = '\0';
	return (src_i + dest_i);
}
