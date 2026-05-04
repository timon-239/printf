/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putchar_pf.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/30 18:50:29 by tireis           #+#    #+#              */
/*   Updated: 2026/05/04 14:07:10 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar_pf(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	return (write(1, &ch, 1));
}
