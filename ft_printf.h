/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/30 20:06:54 by tireis           #+#    #+#              */
/*   Updated: 2026/05/11 19:38:10 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar_pf(int c);
int	ft_putnb_pf(int n);
int	ft_putu_pf(unsigned int n);
int	ft_putstr_pf(char *str);
int	ft_puthex_lower(unsigned int n);
int	ft_puthex_upper(unsigned int n);
int	ft_putptr_pf(unsigned long long ptr);
int	ft_printf(const char *format, ...);

#endif
