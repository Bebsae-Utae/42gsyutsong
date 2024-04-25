/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:44:48 by yutsong           #+#    #+#             */
/*   Updated: 2024/04/25 15:33:08 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

// #include "ft_printf.h"

// static char* ft_strchr(const char* s, int c)
// {
// 	char find;
// 	int i;

// 	find = (unsigned char)c;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == find)
// 			return ((char*)s + i);
// 		i++;
// 	}
// 	if (s[i] == find)
// 		return ((char*)s + i);
// 	return (0);
// }

// static void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

// static void	ft_putstr_fd(char *s, int fd)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return ;
// 	while (s[i++])
// 		ft_putchar_fd(s[i - 1], fd);
// }

// static void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*rtp;

// 	rtp = malloc(count * size);
// 	if (rtp != NULL)
// 		ft_bzero(rtp, count * size);
// 	return (rtp);
// }

// static char	*create_string(unsigned long value, int *strlen)
// {
// 	int				i;
// 	unsigned long	temp;
// 	char			*str;

// 	i = 0;
// 	temp = value;
// 	while (temp != 0)
// 	{
// 		temp = temp / 16;
// 		i++;
// 	}
// 	str = calloc(i + 1, sizeof(char));
// 	*strlen = i - 1;
// 	return (str);
// }


// static int	print_pointer(unsigned long value, int asc)
// {
// 	unsigned long	tempval;
// 	char			*printout;
// 	int				i;
// 	int				*iptr;

// 	iptr = &i;
// 	tempval = value;
// 	printout = create_string(value, iptr);
// 	if (!printout)
// 		return (0);
// 	while (tempval != 0 && i-- >= 0)
// 	{
// 		if ((tempval % 16) < 10)
// 			printout[i + 1] = (tempval % 16) + 48;
// 		else
// 			printout[i + 1] = (tempval % 16) + asc;
// 		tempval = tempval / 16;
// 	}
// 	i = ft_strlen(printout);
// 	i = i + print_string("0x");
// 	ft_putstr_fd(printout, 1);
// 	free(printout);
// 	if (value == 0)
// 		i += print_char('0');
// 	return (i);
// }

// static int	print_int(int n)
// {
// 	int				nb;
// 	unsigned int	i;

// 	nb = n;
// 	i = 1;
// 	if (n < 0 && n != -2147483648)
// 	{
// 		nb = -n;
// 		i++;
// 	}
// 	while (nb > 9)
// 	{
// 		nb = nb / 10;
// 		i++;
// 	}
// 	ft_putnbr_fd(n, 1);
// 	if (n == -2147483648)
// 		return (11);
// 	return (i);
// }

// static char	*create_string(unsigned int value, int *strlen)
// {
// 	int				i;
// 	unsigned int	temp;
// 	char			*str;

// 	i = 0;
// 	temp = value;
// 	while (temp != 0)
// 	{
// 		temp = temp / 16;
// 		i++;
// 	}
// 	str = calloc(i + 1, sizeof(char));
// 	*strlen = i - 1;
// 	return (str);
// }

// static int	print_hex(unsigned int value, int asc)
// {
// 	unsigned int	tempval;
// 	char			*printout;
// 	int				i;
// 	int				*iptr;

// 	iptr = &i;
// 	tempval = value;
// 	printout = create_string(value, iptr);
// 	if (!printout)
// 		return (0);
// 	while (tempval != 0)
// 	{
// 		if ((tempval % 16) < 10)
// 			printout[i] = (tempval % 16) + 48;
// 		else
// 			printout[i] = (tempval % 16) + asc;
// 		tempval = tempval / 16;
// 		i--;
// 	}
// 	ft_putstr_fd(printout, 1);
// 	i = ft_strlen(printout);
// 	free(printout);
// 	if (value == 0)
// 		i += print_char('0');
// 	return (i);
// }

// static void	printout(unsigned int nb)
// {
// 	if (nb > 9)
// 		print_unsigned(nb / 10);
// 	if (nb <= 9)
// 	{
// 		ft_putchar_fd(nb + 48, 1);
// 		return ;
// 	}
// 	ft_putchar_fd((nb % 10) + 48, 1);
// }

// static int	print_unsigned(unsigned int nb)
// {
// 	unsigned int	i;

// 	printout(nb);
// 	i = 1;
// 	while (nb > 9)
// 	{
// 		nb = nb / 10;
// 		i++;
// 	}
// 	return (i);
// }

// static int	print_char(char c)
// {
// 	ft_putchar_fd(c, 1);
// 	return (1);
// }

// static int	print_string(char *s)
// {
// 	unsigned int	i;

// 	i = 0;
// 	if (!s)
// 	{
// 		ft_putstr_fd("(null)", 1);
// 		return (6);
// 	}
// 	while (s[i])
// 		i++;
// 	ft_putstr_fd(s, 1);
// 	return (i);
// }

// static int	check_type(const char *input, void *arg)
// {
// 	int	idx;

// 	idx = 0;
// 	if (*input == 'c')
// 		idx += print_char(arg);
// 	else if (*input == 's')
// 		idx += print_string(arg);
// 	else if (*input == 'p')
// 		idx += print_pointer(arg, 87);
// 	else if (*input == 'd')
// 		idx += print_int(arg);
// 	else if (*input == 'i')
// 		idx += print_int(arg);
// 	else if (*input == 'u')
// 		idx += print_unsigned(arg);
// 	else if (*input == 'x')
// 		idx += print_hex(arg, 87);
// 	else if (*input == 'X')
// 		idx += print_hex((unsigned int)arg, 55);
// 	return (idx);
// }

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	flag;

	flag = 0;
	va_start(args, format);
	// while (*format != '\0')
	// {
	// 	if (*format == '%')
	// 	{
	// 		format ++;
	// 		if (ft_strchr("cspdiuxX", *format))
	// 			flag += check_type(format, va_arg(args, void *));
	// 		else if (*format == '%')
	// 			flag += print_char('%');
	// 	}
	// 	else
	// 		flag += print_char(*format);
	// 	format ++;
	// }
	va_end(args);
	return (flag);
}

int main(void)
{
	ft_printf("%%");
	return (0);
}