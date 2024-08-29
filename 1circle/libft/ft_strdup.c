/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:28:36 by yutsong           #+#    #+#             */
/*   Updated: 2024/03/15 10:42:28 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*new_str;

	len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(new_str))
		return (0);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i ++;
	}
	new_str[i] = '\0';
	return (new_str);
}
