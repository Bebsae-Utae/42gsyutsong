/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:14:49 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/01 12:12:47 by yutsong          ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *s)
{
	int		i;
	int		len;
	char	*new_s;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	new_s = (char *)malloc(sizeof(char) * (len + 1));
	if (!(new_s))
		return (NULL);
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
