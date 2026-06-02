/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putnb_pf.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/30 18:55:32 by tireis           #+#    #+#              */
/*   Updated: 2026/06/02 12:45:37 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnb_pf(int n)
{
	int	len;
	int	res;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		if (ft_putchar_pf('-') == -1)
			return (-1);
		n = -n;
		len++;
	}
	if (n >= 10)
	{
		res = ft_putnb_pf(n / 10);
		if (res == -1)
			return (-1);
		len += res;
	}
	res = ft_putchar_pf((n % 10) + '0');
	if (res == -1)
		return (-1);
	return (len + res);
}
