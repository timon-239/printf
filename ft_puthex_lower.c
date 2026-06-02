/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_puthex_lower.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/30 20:11:56 by tireis           #+#    #+#              */
/*   Updated: 2026/06/02 12:42:17 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_lower(unsigned int n)
{
	int		count;
	int		res;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		res = ft_puthex_lower(n / 16);
		if (res == -1)
			return (-1);
		count += res;
	}
	res = ft_putchar_pf(base[n % 16]);
	if (res == -1)
		return (-1);
	count += res;
	return (count);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%x\n", 255);
	ft_puthex_lower(255);
}*/
