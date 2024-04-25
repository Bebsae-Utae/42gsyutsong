/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:53:41 by yutsong           #+#    #+#             */
/*   Updated: 2024/03/15 10:53:03 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_str;
	char	*result;
	size_t	len_total;

	if (!s1 || !s2)
		return (0);
	len_total = ft_strlen(s1) + ft_strlen(s2);
	join_str = (char *)malloc(sizeof(char) * (len_total + 1));
	if (!join_str)
		return (0);
	result = join_str;
	while (len_total-- > 0)
	{
		if (*s1)
			*join_str = *s1 ++;
		else if (*s2)
			*join_str = *s2 ++;
		join_str ++;
	}
	*join_str = '\0';
	return (result);
}
