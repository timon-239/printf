/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   libftprintf.h                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/30 20:06:54 by tireis           #+#    #+#              */
/*   Updated: 2026/05/04 14:18:55 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar_pf(int c);
int	ft_putnb_pf(int n);
int	ft_putu_pf(unsigned int n);
int	ft_putstr_pf(char *str);
int	ft_puthex_lower(unsigned int n);
int	ft_puthex_upper(unsigned int n);
int	ft_putptr_pf(unsigned long long ptr);
int	ft_printf(const char* format,...);

#endif
