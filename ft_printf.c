/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/30 18:32:41 by tireis           #+#    #+#              */
/*   Updated: 2026/05/05 13:58:52 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	handle_formats2(va_list *args, char c)
{
	int	count;

	count = 0;
	if (c == 'x')
		count += ft_puthex_lower(va_arg(*args, unsigned int));
	else if (c == 'X')
		count += ft_puthex_upper(va_arg(*args, unsigned int));
	else if (c == 'p')
		count += ft_putptr_pf(va_arg(*args, unsigned long long));
	else if (c == 'u')
		count += ft_putu_pf(va_arg(*args, unsigned int));
	return (count);
}

static int	handle_formats(va_list *args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_pf(va_arg(*args, int));
	else if (c == 's')
		count += ft_putstr_pf(va_arg(*args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnb_pf(va_arg(*args, int));
	else if (c == '%')
		count += ft_putchar_pf(c);
	else
		count += handle_formats2(args, c);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_count;
	size_t	i;

	i = 0;
	total_count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			total_count += handle_formats(&args, format[i]);
		}
		else
		{
			ft_putchar_pf(format[i]);
			total_count++;
		}
		i++;
	}
	return (total_count);
}

/*#include <stdio.h>

int	main(void)
{
	unsigned long long	a;
	void				*b;
	int					nb;
	int					x;
	int					y;

	nb = 100;
	a = 4;
	b = &a;
	x = ft_printf("Hallo %s", "HALLO");
	y = printf("Hallo %s", "HALLO");
	printf("\nft = %d, normal = %d\n", x, y);
	ft_printf("Hallo %s, %c, %d, %p, %x, %X", "HALLO", 'A', nb, b, 255, 166);
	printf("\nHallo %s, %c, %d, %p, %x, %X\n\n", "HALLO", 'A', nb, b, 255, 166);
	ft_printf("%c", 'A');
	printf("\n%c\n", 'A');
	ft_printf("%s", "HALLO");
	printf("\n%s\n", "HALLO");
	ft_printf("%d", nb);
	printf("\n%d\n", nb);
	ft_printf("%p", b);
	printf("\n%p\n", b);
	ft_printf("%x", 255);
	printf("\n%x\n", 255);
	ft_printf("%X", 166);
	printf("\n%X\n", 166);
	return (0);
}*/
