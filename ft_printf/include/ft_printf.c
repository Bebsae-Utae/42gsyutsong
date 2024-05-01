/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:44:48 by yutsong           #+#    #+#             */
/*   Updated: 2024/05/01 16:09:16 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

// #include "ft_printf.h"

static void writer(int c)
{
	write(1, &c, 1);
}

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
	// printf("%c", "0123456789"[num%10]);
	// write(1, &"0123456789"[num % 10], 1);
	// writer(num % 10);
	writer("0123456789"[num % 10]);
	return (idx);
}

// static void dptest(int num)
// {
// 	if (num > 9)
// 		dptest(num / 10);
// 	writer(num % 10);
// 	// printf("%d", num % 10);
// }

static void	ft_putchar(char c) {
	write(1, &c, 1);
}

static void	dptest(int nb) {
	if (nb < 0) {
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10) {
		dptest(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10) ft_putchar(nb + 48);
}

static int dtest(va_list args)
{
	int idx;
	int num;

	idx = 0;
	num = va_arg(args, int);
	// printf("%d", num);
	dptest(num);
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

static int putptr(unsigned long long ptr)
{
	int idx;

	idx = 0;
	if (ptr >= 16)
	{
		putptr(ptr / 16);
		putptr(ptr % 16);
		idx ++;
	}
	else
	{
		if (ptr < 10)
			// write(1, (char)('0' + ptr), 1);
			writer(('0' + ptr));
		else
			// write(1, (char)(ptr - 10 + 'a'), 1);
			writer(ptr - 10 + 'a');
		idx ++;
	}
	return (idx);
}

static int print_p(va_list args)
{
	unsigned long long ptr;
	int idx;

	idx = 0;
	ptr = va_arg(args, unsigned long long);
	idx += 2;
	write(1, "0x", 2);
	idx += putptr(ptr);
	return (idx);
	// printf("%d", 99);
}

static int print_i(va_list args);

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
			// write(1, &base[nbr_final[i]], 1);
			writer(base[nbr_final[i]]);
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
		// i += printf("%d", va_arg(args, int));
		// i += print_d(args);
		i += dtest(args);
	else if (*format == 's')
		i += print_s(args);
	else if (*format == 'c')
		i += print_c(args);
	else if (*format == 'p')
		// i += printf("%p", va_arg(args, void *));
		i += print_p(args);
	else if (*format == 'i')
		// i += printf("%i", va_arg(args, int));
		i += print_d(args);
	else if (*format == 'u')
		// i += printf("%u", va_arg(args, unsigned int));
		i += print_xx(args, "0123456789");
	else if (*format == 'x')
		i += print_xx(args, "0123456789abcdef");
		// i += printf("%x", va_arg(args, unsigned int));
	else if (*format == 'X')
		i += print_xx(args, "0123456789ABCDEF");
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
			write(1, "\n", 1);
			// printf("\n");
		}
		format ++;
	}
	va_end(args);
	return (flag);
}

// int main(void)
// {
// 	ft_printf("%d %s %c %p %i %u %x %X %%", 10, "string", 'a', "ww", 20, 30, 40, 50);
// 	// printf("%d", ft_printf("%d %s %c %p %i %u %x %X %%", 10, "string", 'a', "ww", 20, 30, 40, 50));
// 	return (0);
// }