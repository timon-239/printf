/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_puthex_upper.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/30 20:39:18 by tireis           #+#    #+#              */
/*   Updated: 2026/06/02 12:43:31 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_upper(unsigned int n)
{
	int		count;
	char	*base;
	int		res;

	count = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		res = ft_puthex_upper(n / 16);
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
	printf("%X", 160);
	ft_puthex_upper(160);
}*/
