/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:14:49 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/03 14:50:14 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *str, int c)
{
	char	value;
	int		idx;

	value = (unsigned char)c;
	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == value)
			return ((char *)str + idx);
		idx ++;
	}
	if (str[idx] == value)
		return ((char *)str + idx);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	char	*joinstr;
	int		joinstr_len;

	joinstr_len = ft_strlen(s1) + ft_strlen(s2);
	joinstr = (char *)malloc((joinstr_len + 1) * sizeof(char));
	result = joinstr;
	if (!joinstr)
		return (NULL);
	while (joinstr_len-- > 0)
	{
		if (*s1)
			*joinstr = *s1++;
		else if (*s2)
			*joinstr = *s2++;
		joinstr++;
	}
	*joinstr = 0;
	return (result);
}
