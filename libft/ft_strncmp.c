/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:18:53 by yutsong           #+#    #+#             */
/*   Updated: 2024/03/13 15:47:40 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;
	unsigned char	*temp1;
	unsigned char	*temp2;

	idx = 0;
	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (idx < n && (temp1[idx] || temp2[idx]))
	{
		if (temp1[idx] == temp2[idx])
			idx ++;
		else
			return (temp1[idx] - temp2[idx]);
	}
	return (0);
}
