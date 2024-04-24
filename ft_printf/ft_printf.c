/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:44:48 by yutsong           #+#    #+#             */
/*   Updated: 2024/04/24 19:51:25 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

// #include "ft_printf.h"

static char* ft_strchr(const char* s, int c)
{
	char find;
	int i;

	find = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			return ((char*)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char*)s + i);
	return (0);
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i++])
		ft_putchar_fd(s[i - 1], fd);
}




static int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	print_string(char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (s[i])
		i++;
	ft_putstr_fd(s, 1);
	return (i);
}


static int	check_type(const char *input, void *arg)
{
	int	idx;

	idx = 0;
	if (*input == 'c')
		idx += print_char((int)arg);
	else if (*input == 's')
		idx += print_string((char *)arg);
	// else if (*input == 'p')
	// 	idx += print_pointer((unsigned long)arg, 87);
	// else if (*input == 'd')
	// 	idx += print_int((int)arg);
	// else if (*input == 'i')
	// 	idx += print_int((int)arg);
	// else if (*input == 'u')
	// 	idx += print_unsigned((unsigned int)arg);
	// else if (*input == 'x')
	// 	idx += print_hex((unsigned int)arg, 87);
	// else if (*input == 'X')
	// 	idx += print_hex((unsigned int)arg, 55);
	return (idx);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	flag;

	flag = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format ++;
			if (ft_strchr("cspdiuxX", *format))
				flag += check_type(format, va_arg(args, void *));
			else if (*format == '%')
				flag += print_char('%');
		}
		else
			flag += print_char(*format);
		format ++;
	}
	va_end(args);
	return (0);
}

int main(void)
{
	ft_printf("%s", "asd");
	return (0);
}