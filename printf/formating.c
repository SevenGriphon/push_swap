/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:45:06 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/05 16:46:41 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fstring(char *arg)
{
	if (arg == NULL)
	{
		return (putstr("(null)"));
	}
	return (putstr(arg));
}

int	finteger(int arg)
{
	char	*i;
	int		printed;

	i = ft_itoa(arg);
	printed = putstr(i);
	free(i);
	return (printed);
}

int	fhex(unsigned long arg, char c)
{
	char	*i;
	char	*base;
	int		printed;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = ft_bitoa(arg, base);
	printed = putstr(i);
	free(i);
	return (printed);
}

int	funsigned(unsigned int n)
{
	char	c;
	int		len;

	len = 0;
	c = n % 10 + '0';
	if (n / 10 != 0)
		len += funsigned(n / 10);
	len ++;
	write(1, &c, 1);
	return (len);
}

int	fpointer(void *arg)
{
	if (arg == NULL)
	{
		return (putstr("(nil)"));
	}
	return (putstr("0x") + fhex((unsigned long) arg, 'x'));
}
