/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:44:48 by yutsong           #+#    #+#             */
/*   Updated: 2024/05/02 15:57:55 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int print_num(int num)
// {
// 	int idx;

// 	idx = 0;
// 	if (num == -2147483648)
// 		write(1, "-2147483648", 11);
// 	else if (num < 0)
// 	{
// 		write(1, "-", 1);
// 		idx ++;
// 		num *= (-1);
// 	}
// 	else if (num >= 10)
// 	{
// 		idx ++;
// 		print_num(num / 10);
// 	}
// 	idx ++;
// 	writer("0123456789"[num % 10]);
// 	return (idx);
// }

// static void	dptest(int nb) {
// 	if (nb < 0) {
// 		writer('-');
// 		nb = -nb;
// 	}
// 	if (nb >= 10) {
// 		dptest(nb / 10);
// 		nb = nb % 10;
// 	}
// 	if (nb < 10) ft_putchar(nb + 48);
// }

// static int dtest(va_list args)
// {
// 	int idx;
// 	int num;

// 	idx = 0;
// 	num = va_arg(args, int);
// 	dptest(num);
// 	return (idx);
// }

// static int ft_putnbr(int nb, int idx) {
// 	if (nb < 0) {
// 		ft_putchar('-');
// 		nb = -nb;
// 		idx ++;
// 	}
// 	if (nb >= 10) {
// 		ft_putnbr(nb / 10, idx);
// 		nb = nb % 10;
// 		idx ++;
// 	}
// 	if (nb < 10) ft_putchar(nb + 48);
// 	idx ++;
// 	return (idx);
// }

// static int print_d(va_list args)
// {
// 	unsigned int idx;
// 	int num;

// 	num = va_arg(args, int);
// 	idx = 1;
// 	if (va_arg(args, int) == -2147483648)
// 	{
// 		write(1, "-2147483648", 11);
// 		return (11);
// 	}
// 	idx = ft_putnbr(num, idx);
// 	// if (va_arg(args, int) < 0 && va_arg(args,int) != -2147483648)
// 	// {
// 	// 	num = - va_arg(args, int);
// 	// 	idx ++;
// 	// }
// 	// while (num > 9)
// 	// {
// 	// 	num /= 10;
// 	// 	idx ++;
// 	// }
// 	// print_num(va_arg(args, int));

// 	return (idx);	
// }

// static int print_xx(va_list args, char *base)
// {
// 	int	size_base;
// 	int	nbr_final[100];
// 	int	i;
// 	int nbr;

// 	nbr = va_arg(args, int);
// 	i = 0;
// 	size_base = 0;
// 	if (check_base(base))
// 	{
// 		if (nbr < 0)
// 		{
// 			nbr = -nbr;
// 			write(1, "-", 1);
// 		}
// 		while (base[size_base])
// 			size_base++;
// 		while (nbr)
// 		{
// 			nbr_final[i] = nbr % size_base;
// 			nbr = nbr / size_base;
// 			i++;
// 		}
// 		while (--i >= 0)
// 			writer(base[nbr_final[i]]);
// 	}
// 	return (i);
// }



static int	type_selecter(const char *format, va_list args)
{
	int i;

	i = 0;
	if (*format == 'd')
		// i += dtest(args);
		i += print_d(args);
	else if (*format == 's')
		i += print_s(args);
	else if (*format == 'c')
		i += print_c(args);
	else if (*format == 'p')
		i += print_p(args);
	else if (*format == 'i')
		i += print_d(args);
	else if (*format == 'u')
		i += print_u(args);
	// else if (*format == 'x')
	// 	i += print_xx(args, "0123456789abcdef");
	// else if (*format == 'X')
	// 	i += print_xx(args, "0123456789ABCDEF");	
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