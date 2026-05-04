/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_puthex_pf.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/30 20:11:56 by tireis           #+#    #+#              */
/*   Updated: 2026/04/30 20:38:34 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthex_lower(unsigned int n)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex_lower(n / 16);
	count += ft_putchar_pf(base[n % 16]);
	return (count);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%x\n", 255);
	ft_puthex_lower(255);
}*/
