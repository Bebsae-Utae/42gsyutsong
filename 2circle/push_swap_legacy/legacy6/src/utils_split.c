/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:12:53 by yutsong           #+#    #+#             */
/*   Updated: 2024/08/10 17:27:26 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = (char **)malloc((counter_word(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if ((setter_word(s, c, result, 0)) == -1)
	{
		free_all(result);
		return (NULL);
	}
	return (result);
}

int	counter_word(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			str ++;
		else
		{
			count ++;
			while (*str != c && *str)
				str ++;
		}
	}
	return (count);
}

int	setter_word(char const *str, char c, char **result, int idx)
{
	int	len;

	while (*str)
	{
		if (*str == c)
			str ++;
		else
		{
			len = 0;
			while (*str != c && *str)
			{
				str ++;
				len ++;
			}
			if (len == 0)
			{
				result[idx] = NULL;
				free_all(result);
				return (-1);
			}
			result[idx] = (char *)malloc((len + 1) * sizeof(char));
			if (!result[idx])
			{
				result[idx] = NULL;
				free_all(result);
				return (-1);
			}
			ft_strlcpy((char *)result[idx ++], (char *)str - len, len + 1);
		}
	}
	result[idx] = 0;
	return (1);
}
