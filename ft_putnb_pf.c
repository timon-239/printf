/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putnb_pf.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/30 18:55:32 by tireis           #+#    #+#              */
/*   Updated: 2026/05/04 13:02:10 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnb_pf(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = 11;
		return (len);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		len++;
	}
	if (n >= 10)
	{
		ft_putnb_pf(n / 10);
	}
	len += ft_putchar_pf((n % 10) + '0');
	return (len);
}
