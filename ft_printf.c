/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/30 18:32:41 by tireis           #+#    #+#              */
/*   Updated: 2026/06/04 19:51:31 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_formats2(va_list *args, char c)
{
	int		count;
	void	*ptr;

	count = 0;
	if (c == 'x')
		count = ft_puthex_lower(va_arg(*args, unsigned int));
	else if (c == 'X')
		count = ft_puthex_upper(va_arg(*args, unsigned int));
	else if (c == 'p')
	{
		ptr = va_arg(*args, void *);
		count = ft_putptr_pf((unsigned long long)ptr);
	}
	else if (c == 'u')
		count = ft_putu_pf(va_arg(*args, unsigned int));
	else
	{
		count += ft_putchar_pf('%');
		count += ft_putchar_pf(c);
	}
	return (count);
}

static int	handle_formats(va_list *args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar_pf(va_arg(*args, int));
	else if (c == 's')
		count = ft_putstr_pf(va_arg(*args, char *));
	else if (c == 'd' || c == 'i')
		count = ft_putnb_pf(va_arg(*args, int));
	else if (c == '%')
		count = ft_putchar_pf(c);
	else
		count = handle_formats2(args, c);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_count;
	size_t	i;
	int		res;

	i = 0;
	total_count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (va_end(args), -1);
			res = handle_formats(&args, format[i + 1]);
			i++;
		}
		else
			res = ft_putchar_pf(format[i]);
		if (res == -1)
			return (va_end(args), -1);
		total_count += res;
		i++;
	}
	return (va_end(args), total_count);
}
/*
#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	int	res_ft;
	int	res_org;

	a = 42;
	b = 99;
	res_ft = ft_printf("%c", 'a');
	printf("\n");
	res_org = printf("%c", 'a');
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%c", 'Z');
	printf("\n");
	res_org = printf("%c", 'Z');
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%c", 65);
	printf("\n");
	res_org = printf("%c", 65);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%c", 0);
	printf("\n");
	res_org = printf("%c", 0);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("test%ctest", 'X');
	printf("\n");
	res_org = printf("test%ctest", 'X');
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%c%c%c", 'a', 'b', 'c');
	printf("\n");
	res_org = printf("%c%c%c", 'a', 'b', 'c');
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%s", "hello");
	printf("\n");
	res_org = printf("%s", "hello");
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%s", "");
	printf("\n");
	res_org = printf("%s", "");
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%s", NULL);
	printf("\n");
	res_org = printf("%s", NULL);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%s %s", "foo", "bar");
	printf("\n");
	res_org = printf("%s %s", "foo", "bar");
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%s", "Hello, World!");
	printf("\n");
	res_org = printf("%s", "Hello, World!");
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%d", 0);
	printf("\n");
	res_org = printf("%d", 0);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%d", 42);
	printf("\n");
	res_org = printf("%d", 42);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%d", -42);
	printf("\n");
	res_org = printf("%d", -42);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%d", INT_MAX);
	printf("\n");
	res_org = printf("%d", INT_MAX);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%d", INT_MIN);
	printf("\n");
	res_org = printf("%d", INT_MIN);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%d", -1);
	printf("\n");
	res_org = printf("%d", -1);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%i", 42);
	printf("\n");
	res_org = printf("%i", 42);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%i", -42);
	printf("\n");
	res_org = printf("%i", -42);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%i", 0);
	printf("\n");
	res_org = printf("%i", 0);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%i", INT_MIN);
	printf("\n");
	res_org = printf("%i", INT_MIN);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%u", 0);
	printf("\n");
	res_org = printf("%u", 0);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%u", 42);
	printf("\n");
	res_org = printf("%u", 42);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%u", 4294967295U);
	printf("\n");
	res_org = printf("%u", 4294967295U);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%u", 2147483648U);
	printf("\n");
	res_org = printf("%u", 2147483648U);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%x", 0);
	printf("\n");
	res_org = printf("%x", 0);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%x", 255);
	printf("\n");
	res_org = printf("%x", 255);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%x", 16);
	printf("\n");
	res_org = printf("%x", 16);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%x", 4294967295U);
	printf("\n");
	res_org = printf("%x", 4294967295U);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%x", 15);
	printf("\n");
	res_org = printf("%x", 15);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%X", 0);
	printf("\n");
	res_org = printf("%X", 0);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%X", 255);
	printf("\n");
	res_org = printf("%X", 255);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%X", 4294967295U);
	printf("\n");
	res_org = printf("%X", 4294967295U);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%X", 15);
	printf("\n");
	res_org = printf("%X", 15);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%p", &a);
	printf("\n");
	res_org = printf("%p", &a);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%p", NULL);
	printf("\n");
	res_org = printf("%p", NULL);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%p %p", &a, &b);
	printf("\n");
	res_org = printf("%p %p", &a, &b);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%%");
	printf("\n");
	res_org = printf("%%");
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("100%%");
	printf("\n");
	res_org = printf("100%%");
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%%%d%%", 42);
	printf("\n");
	res_org = printf("%%%d%%", 42);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("hello world");
	printf("\n");
	res_org = printf("hello world");
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%c %s %d", 'A', "hi", 42);
	printf("\n");
	res_org = printf("%c %s %d", 'A', "hi", 42);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%d + %d = %d", 1, 2, 3);
	printf("\n");
	res_org = printf("%d + %d = %d", 1, 2, 3);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%s: %d (0x%x)", "val", 255, 255);
	printf("\n");
	res_org = printf("%s: %d (0x%x)", "val", 255, 255);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("%d %i %u %x %X", 42, 42, 42, 42, 42);
	printf("\n");
	res_org = printf("%d %i %u %x %X", 42, 42, 42, 42, 42);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("min=%d max=%d", INT_MIN, INT_MAX);
	printf("\n");
	res_org = printf("min=%d max=%d", INT_MIN, INT_MAX);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	res_ft = ft_printf("neg: %d hex: %x", -1, 255);
	printf("\n");
	res_org = printf("neg: %d hex: %x", -1, 255);
	printf("\n");
	printf("ft=%d org=%d\n\n", res_ft, res_org);
	return (0);
}

*/
#include <stdio.h>

int	main(void)
{
	int	org;
	int	mein;
	int	org2;
	int	mein2;

	mein = ft_printf("abc%");
	printf("\n");
	org = printf("abc%");
	printf("\n");
	org2 = printf("hallo %y hallo");
	printf("\n");
	mein2 = ft_printf("hallo %y hallo");
	printf("\n");
	printf("MEINS : %d , ORG : %dn mein2 : %d , org2 %d", mein, org, mein2,
		org2);
}

/*#include <stdio.h>

int	main(void)
{
	unsigned long long	a;
	void				*b;
	int					nb;
	int					x;
	int					y;
	int					k;
	int					counter;
	int					counter_org;
	char				*ptr;

	ptr = NULL;
	nb = 100;
	a = 4;
	b = &a;
	x = ft_printf("Hallo %s", "HALLO");
	y = printf("Hallo %s", "HALLO");
	printf("\nft = %d, normal = %d\n", x, y);
	printf("\n");
	ft_printf("HIER TEST:");
	ft_printf("Test %z");
	printf("\n");
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
	printf("\n");
	counter = ft_printf("%p %p ", ptr, ptr);
	printf("\n");
	counter_org = printf("(nil) (nil) ");
	printf("\n");
	printf("%d", counter);
	printf("\n");
	printf("%d", counter_org);
	printf("\n");
	return (0);
}*/
