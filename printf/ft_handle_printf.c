/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_printf.c                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: ldoucet <ldoucet@learner.42.tech>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2026/05/09 10:39:37 by ldoucet           #+#    #+#            */
/*   Updated: 2026/05/09 10:39:42 by ldoucet          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = ft_putchar('0');
	count += ft_putchar('x');
	count += ft_puthex((unsigned long)ptr, "0123456789abcdef");
	return (count);
}

int	ft_handle_format(char spec, va_list *args)
{
	char	c;

	if (spec == 'c')
	{
		c = (char)va_arg(*args, int);
		write(1, &c, 1);
		return (1);
	}
	else if (spec == 's')
		return (ft_strstring(va_arg(*args, char *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (spec == 'u')
		return (ft_putunsigned(va_arg(*args, unsigned int)));
	else if (spec == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (spec == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (spec == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (spec == '%')
		return (write(1, "%", 1));
	ft_putchar('%');
	return (ft_putchar(spec) + 1);
}
