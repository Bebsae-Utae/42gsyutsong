/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:09:32 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/25 11:35:24 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	inttemp;

	i = 0;
	minus = 1;
	inttemp = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i ++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			minus *= -1;
		i ++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		inttemp = inttemp * 10 + (str[i] - 48);
		i ++;
	}
	return (inttemp * minus);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s ++;
	}
}
