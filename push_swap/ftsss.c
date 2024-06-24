/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:44:52 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/24 17:06:14 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char	*str)
{
	int	idx;
	int	minus;
	int	result;

	idx = 0;
	minus = 1;
	result = 0;
	while (str[idx] >= 7 && str[idx] <= 13)
		idx ++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
		 	minus *= -1;
		idx ++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		result *= 10;
		result += str[idx] - '0';
		idx ++;
	}
	return (result * minus);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s ++;
	}
	write(fd, "\n", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd((-n), fd);
	}
	else if (n < 10 && n >= 0)
		ft_putchar_fd(n + '0', fd);
	else if (n > 0)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

static void	free_all(char **result)
{
	int	idx;

	idx = 0;
	while (!result[idx])
		free(result[idx ++]);
	free(result);
}

static int	counter_word(char const *str, char c)
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

static int	setter_word(char const *str, char c, char **result, int idx)
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
			result[idx] = (char *)malloc((len + 1) * sizeof(char));
			if (!result[idx])
			{
				free_all(result);
				return (0);
			}
			ft_strlcpy((char *)result[idx ++], (char *)str - len, len + 1);
		}
	}
	result[idx] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = (char **)malloc((counter_word(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if ((setter_word(s, c, result, 0)) == -1)
		return (NULL);
	return (result);
}

int	ft_strlcpy(char *dest, const char *src, int size)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(src);
	if (!size)
		return (len);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (len);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
