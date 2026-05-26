/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:48:10 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/05 17:09:41 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_percent(char c, va_list args)
{
	int	printed;

	printed = 0;
	if (c == 's')
		return (fstring(va_arg(args, char *)));
	else if (c == 'c')
	{
		ft_putchar(va_arg(args, int));
		return (1);
	}
	else if (c == '%')
	{
		ft_putchar('%');
		return (1);
	}
	else if (c == 'i' || c == 'd')
		return (finteger(va_arg(args, int)));
	else if (c == 'x' || c == 'X')
		return (fhex(va_arg(args, unsigned int), c));
	else if (c == 'u')
		return (funsigned(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (fpointer(va_arg(args, void *)));
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		printed;
	va_list	args;

	va_start(args, format);
	printed = 0;
	i = 0;
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			printed += handle_percent(format[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			printed++;
		}
		if (format[i] != 0)
			i++;
	}
	return (printed);
}
