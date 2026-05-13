/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putstr_pf.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/30 18:50:40 by tireis           #+#    #+#              */
/*   Updated: 2026/05/13 13:08:39 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
		len++;
	}
	return (len);
}
