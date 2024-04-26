/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:44:48 by yutsong           #+#    #+#             */
/*   Updated: 2024/04/26 13:49:21 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

// #include "ft_printf.h"

static int print_c(va_list args)
{
	int data;

	data = va_arg(args, int);
	write(1, &data, 1);
	return (1);
}

static int type_selecter(const char *format, va_list args)
{
	int i;

	i = 0;
	if (*format == 'd')
		i += printf("%d", va_arg(args, int));
	else if (*format == 's')
		i += printf("%s", va_arg(args, char *));
	else if (*format == 'c')
		i += print_c(args);
	else if (*format == 'p')
		i += printf("%p", va_arg(args, void *));
	else if (*format == 'i')
		i += printf("%i", va_arg(args, int));
	else if (*format == 'u')
		i += printf("%u", va_arg(args, unsigned int));
	else if (*format == 'x')
		i += printf("%x", va_arg(args, unsigned int));
	else if (*format == 'X')
		i += printf("%X", va_arg(args, unsigned int));		
	return (i);				
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
			flag = type_selecter(format, args);
			printf(" ");
		}
		format ++;
	}
	va_end(args);
	return (flag);
}

int main(void)
{
	printf("%d", ft_printf("%d %s %c %p %i %u %x %X", 20, "sa", 'a', "ww", 30, 40, 50, 60));
	return (0);
}