/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:18:33 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/03 14:50:56 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*checkline(char *keepsaveline)
{
	if (!keepsaveline)
	{
		keepsaveline = (char *)malloc(sizeof(char) * 1);
		if (!keepsaveline)
			return (NULL);
		keepsaveline[0] = '\0';
		return (keepsaveline);
	}
	return (keepsaveline);
}

static char	*onetime_reader(int fd, char *keepsaveline, char *tempsaveline)
{
	int		countoneline;
	char	*temp;

	while (1)
	{
		countoneline = read(fd, tempsaveline, BUFFER_SIZE);
		if (countoneline == -1)
			return (NULL);
		else if (countoneline == 0)
			break ;
		tempsaveline[countoneline] = '\0';
		keepsaveline = checkline(keepsaveline);
		temp = keepsaveline;
		keepsaveline = ft_strjoin(temp, tempsaveline);
		if (!keepsaveline)
			return (NULL);
		free(temp);
		temp = NULL;
		if (ft_strchr(keepsaveline, '\n'))
			break ;
	}
	return (keepsaveline);
}

static char	*splitter(char *printline, unsigned int start, size_t len)
{
	char	*keepsaveline;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!printline)
		return (NULL);
	keepsaveline = (char *)malloc(sizeof(char) * (len + 1));
	if (!keepsaveline)
		return (NULL);
	while (printline[i])
	{
		if (i >= start && j < len)
		{
			keepsaveline[j] = printline[i];
			j ++;
		}
		i ++;
	}
	keepsaveline[j] = '\0';
	printline[start] = '\0';
	return (keepsaveline);
}

static char	*splitline(char *printline, char *keepsaveline)
{
	int	idx;

	idx = 0;
	while (printline[idx] != '\0' && printline[idx] != '\n')
		idx ++;
	if (printline[idx] == '\0')
		return (NULL);
	keepsaveline = splitter(printline, idx + 1, ft_strlen(printline) - idx);
	if (!keepsaveline)
		return (NULL);
	if (keepsaveline[0] == '\0')
	{
		free(keepsaveline);
		keepsaveline = NULL;
		return (NULL);
	}
	return (keepsaveline);
}

char	*get_next_line(int fd)
{
	static char	*keepsaveline;
	char		*printoneline;
	char		*tempsaveline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tempsaveline = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tempsaveline)
		return (NULL);
	printoneline = onetime_reader(fd, keepsaveline, tempsaveline);
	free(tempsaveline);
	tempsaveline = NULL;
	if (!printoneline)
		return (NULL);
	keepsaveline = splitline(printoneline, keepsaveline);
	return (printoneline);
}
