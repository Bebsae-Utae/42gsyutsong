/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:47:33 by yutsong           #+#    #+#             */
/*   Updated: 2024/05/02 15:55:32 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		print_percent();
int		print_s(va_list args);
int		print_c(va_list args);
int		print_p(va_list args);
int		print_u(va_list args);
int		print_d(va_list args);

int		ft_printf(const char *input, ...);
void	writer(int c);
void	ft_putchar(char c);
int		check_base(char *base);
void	ft_putnbr_base(int nbr, char *base);

#endif
