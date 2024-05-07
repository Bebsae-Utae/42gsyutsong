/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:44:48 by yutsong           #+#    #+#             */
/*   Updated: 2024/05/07 14:37:53 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type_selecter(const char *format, va_list args)
{
	int	i;

	i = 0;
	if (*format == 's')
		i += print_s(args);
	else if (*format == 'c')
		i += print_c(args);
	else if (*format == 'd' || *format == 'i')
		i += print_d(args);
	else if (*format == 'p')
		i += print_p(args);
	else if (*format == 'u')
		i += print_u(args);
	else if (*format == 'x')
		i += print_xx(args, 'a');
	else if (*format == 'X')
		i += print_xx(args, 'A');
	else if (*format == '%')
		i += print_percent();
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	flag;

	flag = 0;
	va_start(args, format);
	if (*format == 0)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format ++;
			flag += type_selecter(format, args);
		}
		else
		{
			ft_putchar(*format);
			flag ++;
		}
		format ++;
	}
	va_end(args);
	return (flag);
}
