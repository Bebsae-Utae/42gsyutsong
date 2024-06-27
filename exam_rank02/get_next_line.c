/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:45:57 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/27 11:49:53 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static char	*ft_strdup(char *src)
{
	char	*ptr;
	int		src_len;
	int		idx;

	idx = 0;
	src_len = ft_strlen(src);
	ptr = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!ptr)
		return (0);
	while (idx < src_len)
	{
		ptr[idx] = src[idx];
		idx ++;
	}
	ptr[idx] = '\0';
	return (ptr);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	char	*joinstr;
	int		joinstr_len;

	joinstr_len = ft_strlen(s1) + ft_strlen(s2);
	joinstr = (char *)malloc(sizeof(char) * (joinstr_len + 1));
	result = joinstr;
	if (!joinstr)
		return (NULL);
	while (joinstr_len-- > 0)
	{
		if (*s1)
			*joinstr = *s1 ++;
		else if (*s2)
			*joinstr = *s2 ++;
		joinstr ++;
	}
	*joinstr = 0;
	return (result);
}

static char	*ft_substr(char *s, unsigned int start, int len)
{
	int		idx1;
	int		idx2;
	char	*sub;

	idx1 = 0;
	idx2 = 0;
	if (!s)
		return (NULL);
	if (!(sub = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[idx1])
	{
		if (idx1 >= start && idx2 < len)
		{
			sub[idx2] = s[idx1];
			idx2 ++;
		}
		idx1 ++;
	}
	sub[idx2] = '\0';
	return (sub);
}

static int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx ++;
	return (idx);
}

static char	ft_strchr(char *s, int c)
{
	char	value;
	int		idx;

	value = (unsigned char)c;
	idx = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] == value)
			return ((char *)s + idx);
		idx ++;
	}
	if (s[idx] == value)
		return ((char *)s + idx);
	return (NULL);
}

static char	*line_reader(int fd, char *buff, char *backup)
{
	int		count;
	char	*temp_pointer;

	count = 1;
	while (count)
	{
		count = read(fd, buff, 42);
		if (count == -1)
			return (0);
		else if (count == 0)
			break ;
		buff[count] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp_pointer = backup;
		backup = ft_strjoin(temp_pointer, buff);
		if (!backup)
			return (NULL);
		free(temp_pointer);
		temp_pointer = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract(char *line)
{
	int		idx;
	char	*result;

	idx = 0;
	while (line[idx] != '\n' && line[idx] != '\0')
		idx ++;
	if (line[idx] != '\0')
		return (0);
	result = ft_substr(line, idx + 1, ft_strlen(line) - idx);
	if (!result)
		return (NULL);
	if (result[0] == '\0')
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	line[idx + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buff;
	char		*line;

	if (fd < 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (43));
	if (!buff)
		return (NULL);
	line = line_reader(fd, buff, backup);
	free(buff);
	buff = NULL;
	if (!line)
		return (NULL);
	backup = extract(line);
	return (line);
}