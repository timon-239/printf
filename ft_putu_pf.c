/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putu_pf.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/30 19:50:02 by tireis           #+#    #+#              */
/*   Updated: 2026/05/13 13:08:47 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putu_pf(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putu_pf(n / 10);
	}
	count += ft_putchar_pf((n % 10) + '0');
	return (count);
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
