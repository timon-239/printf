/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putptr_pf.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/30 20:43:53 by tireis           #+#    #+#              */
/*   Updated: 2026/06/02 12:46:35 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexhelp(unsigned long long n)
{
	int		count;
	int		res;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		res = ft_hexhelp(n / 16);
		if (res == -1)
			return (-1);
		count += res;
	}
	res = ft_putchar_pf(base[n % 16]);
	if (res == -1)
		return (-1);
	return (count + res);
}

int	ft_putptr_pf(unsigned long long ptr)
{
	int	count;
	int	res;

	if (ptr == 0)
		return (ft_putstr_pf("(nil)"));
	res = ft_putstr_pf("0x");
	if (res == -1)
		return (-1);
	count = res;
	res = ft_hexhelp(ptr);
	if (res == -1)
		return (-1);
	return (count + res);
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
