/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:47:33 by yutsong           #+#    #+#             */
/*   Updated: 2024/05/08 11:13:39 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		print_percent(void);
int		print_s(va_list args);
int		print_c(va_list args);
int		print_p(va_list args);
int		print_u(va_list args);
int		print_d(va_list args);
int		print_xx(va_list args, char c);

int		ft_printf(const char *input, ...);
void	ft_putchar(char c);
void	putptr(unsigned long long ptr, char c);

#endif
