/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putptr_pf.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/30 20:43:53 by tireis           #+#    #+#              */
/*   Updated: 2026/05/04 13:08:00 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_hexhelp(unsigned long long n)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_hexhelp(n / 16);
	count += ft_putchar_pf(base[n % 16]);
	return (count);
}

int	ft_putptr_pf(unsigned long long ptr)
{
	int	count;

	ft_putstr_pf("0x");
	count = 2;
	count += ft_hexhelp(ptr);
	return (count);
}

/*#include <stdio.h>

int	main(void)
{
	unsigned long long	a;
	void				*b;

	a = 4;
	b = &a;
	printf("%p\n", b);
	ft_print_ptr((unsigned long long)b);
}*/
