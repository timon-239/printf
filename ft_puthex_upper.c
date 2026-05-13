/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_puthex_upper.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/30 20:39:18 by tireis           #+#    #+#              */
/*   Updated: 2026/05/13 13:08:00 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_upper(unsigned int n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex_upper(n / 16);
	count += ft_putchar_pf(base[n % 16]);
	return (count);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%X", 160);
	ft_puthex_upper(160);
}*/
