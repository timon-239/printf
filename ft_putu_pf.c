/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putu_pf.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/30 19:50:02 by tireis           #+#    #+#              */
/*   Updated: 2026/06/02 12:49:22 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putu_pf(unsigned int n)
{
	int	count;
	int	res;

	count = 0;
	if (n >= 10)
	{
		res = ft_putu_pf(n / 10);
		if (res == -1)
			return (-1);
		count += res;
	}
	res = ft_putchar_pf((n % 10) + '0');
	if (res == -1)
		return (-1);
	return (count + res);
}

/*
#include <stdio.h>

int	main(void)
{
	unsigned int	a;
	int				count;

	a = 300;
	count = ft_putu_pf(a);
	printf("\n%u", count);
}*/
