/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:44:48 by yutsong           #+#    #+#             */
/*   Updated: 2024/04/29 19:00:56 by yutsong          ###   ########.fr       */
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

static int print_s(va_list args)
{
	char *data;
	int idx;

	idx = 0;
	data = va_arg(args, char *);
	while (data[idx])
	{
		write(1, &data[idx], 1);
		idx ++;
	}
	return (idx);
}

static int print_num(int num)
{
	int idx;

	idx = 0;
	if (num == -2147483648)
		write(1, "-2147483648", 11);
	else if (num < 0)
	{
		write(1, "-", 1);
		idx ++;
		num *= (-1);
	}
	else if (num >= 10)
	{
		idx ++;
		print_num(num / 10);
	}
	idx ++;
	write(1, &"0123456789"[num % 10], 1);
	return (idx);
}

static int print_d(va_list args)
{
	unsigned int idx;
	int num;

	num = va_arg(args, int);
	idx = 1;
	if (va_arg(args, int) < 0 && va_arg(args,int) != -2147483648)
	{
		num = - va_arg(args, int);
		idx ++;
	}
	while (num > 9)
	{
		num /= 10;
		idx ++;
	}
	print_num(va_arg(args, int));
	if (va_arg(args, int) == -2147483648)
		return (11);
	return (idx);	
}

static int print_p(va_list args)
{
	unsigned long long ptr;
	int idx;
	int *idxptr;

	idx = 0;
	ptr = va_arg(args, unsigned long long);
	idx += 2;
	printf("%d", 99);
	// write(1, "0x", 2);

	return (idx);
}



static int print_i(va_list args);
static int print_u(va_list args);

static int		check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

static int print_xx(va_list args, char *base)
{
	int	size_base;
	int	nbr_final[100];
	int	i;
	int nbr;

	nbr = va_arg(args, int);
	i = 0;
	size_base = 0;
	if (check_base(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			write(1, "-", 1);
		}
		while (base[size_base])
			size_base++;
		while (nbr)
		{
			nbr_final[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
		while (--i >= 0)
			write(1, &base[nbr_final[i]], 1);
	}
}

static int print_percent()
{
	write(1, "%", 1);
	return (1);
}

static int type_selecter(const char *format, va_list args)
{
	int i;

	i = 0;
	if (*format == 'd')
		i += printf("%d", va_arg(args, int));
		// i += print_d(args);
	else if (*format == 's')
		i += print_s(args);
	else if (*format == 'c')
		i += print_c(args);
	else if (*format == 'p')
		// i += printf("%p", va_arg(args, void *));
		i += print_p(args);
	else if (*format == 'i')
		i += printf("%i", va_arg(args, int));
	else if (*format == 'u')
		i += printf("%u", va_arg(args, unsigned int));
	else if (*format == 'x')
		i+= print_xx(args, "0123456789abcdef");
		// i += printf("%x", va_arg(args, unsigned int));
	else if (*format == 'X')
		i+= print_xx(args, "0123456789ABCDEF");
		// i += printf("%X", va_arg(args, unsigned int));	
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
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format ++;
			flag += type_selecter(format, args);
			write(1, " ", 1);
			printf(" ");
		}
		format ++;
	}
	va_end(args);
	return (flag);
}

int main(void)
{
	printf("%d", ft_printf("%d %s %c %p %i %u %x %X %%", 10, "string", 'a', "ww", 20, 30, 40, 50));
	return (0);
}